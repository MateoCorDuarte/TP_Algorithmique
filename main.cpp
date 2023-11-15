/*
 * Étant donné un entier strictement positif X et deux opérations suivantes:
- * 2: Multiplication par 2.
- / 3: Division par 3.
Trouvez une solution pour transformer 1 en X.
Par exemple, si X = 10, une solution possible est la suivante:
1 * 2 * 2 * 2 * 2 / 3 * 2 = 10
Le programme doit afficher la chaîne de caractères “1 * 2 * 2 * 2 * 2 / 3 * 2 = 10”. X est donné à partir
du clavier.
 *
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>


//#include "Ex1.h"
using namespace std;
void ex1(int x);
//vector<int> ex2(const int arr[], int n);
vector<int> Ex2(const vector<int>& sequence, int n);

//vector<int> dp(1, 1);//this vector saves the length of the subsequences
vector<int> prevIndex(1, -1);//saves indexes of the previous elements in the subsequence
int LSI=0;

int main() {

    //Exercise 1
    /*vector <int> order;
    int x;
    cout << "Type your integer: ";
    cin >> x;
    ex1(x);*/
    //--------------------------------------------------------------------------------------
    //Exercise 2;

    ifstream inputFile("INPMONOSEQ.TXT");
    ofstream outputFile("OUTMONOSEQ.TXT");
    if(inputFile.is_open() && outputFile.is_open()){
        //Here I was trying to use the files but there is a problem to read the files that I didn't had the
        //time to correct
        /*
        string line;
        getline(inputFile, line);

        stringstream StringStream(line);
        int n;
        StringStream >> n;
        inputFile >> n;
        vector<int> sequence(n);
        int number;
        while (StringStream >> number) {
            sequence.push_back(number);
            cout<<""<<number<<""<<endl;
        }

        //As it was not possible to use the txt file I will use an array from internet
        vector<int> sequence = {1, 6, 11, 5, 10, 15, 20, 2, 4, 9};
        int n = sequence.size();
        vector<int> subsequence=Ex2(sequence,n);

        outputFile << LSI << endl;

        for (int i = 0; i < LSI; ++i) {
            outputFile << "a[" << prevIndex[i]<< "] = " << subsequence[i] << endl;
        }*/
    }
    inputFile.close();
    outputFile.close();

    //As it was not possible to use the txt file I leave this arrays to test the function.
    vector<int> sequence = {1, 6, 11, 5, 10, 15, 20, 2, 4, 9};//{8,3,4,6,5,2,0,7,9,1};{ 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sequence.size();
    vector<int> subsequence=Ex2(sequence,n);
    cout<<"The size of the sequence is "<<LSI<<endl;
    for(int i=0;i<subsequence.size();i++){
        cout<<"\t"<<subsequence[i];
    }

    prevIndex.clear();
    return 0;

}

void ex1(int x){
    /*We follow the Collatz Conjecture
     * Any integer number X can reach 1 if it's either divided by 2
     * or its multiplied times 3 and added 1.
     * To answer this exercise we use this rule to build the path
     * and then follow this order to go from 1 to X*/
    int result=1;

    vector <int> order;

    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
            order.push_back(2);
            //cout<<"/2 ";
        } else {
            //cout<<"("<<x<<"*3+1)";
            x = (3 * x) + 1;
            order.push_back(3);
        }
    }
    //cout<<"=1\n";

    //After finding the path from 1 to X we use the vector to return from 1 to X.
    cout << "1";
    for (int i = order.size(); i >= 0; i--) {
        if (order[i]==2){
            result = result *2;
            cout << "*2";}
        if (order[i]==3){
            result = result/3;
            cout << "/3";}
    }
    cout << "=" << result;

}

vector<int> Ex2(const vector<int>& sequence, int n) {//const vector<int>& sequence
    //int n = sequence.size();
    //vector<int> dp(n, 1);//this vector saves the length of the subsequences
    //vector<int> prevIndex(n, -1);//saves indexes of the previous elements in the subsequence
    int dp[n];
    prevIndex.resize(n, -1);

    /*the first loop looks at each element from the array
     * to then be compared with the previous elements
     * in the second loop*/
    for (int i = 1; i < n; ++i) {
        dp[i]=1;
        for (int j = 0; j < i; ++j) {
            /*This conditional fist evaluates if the next number is bigger
             * than the previous one, them compare if by adding this number
             * the subsequence would be bigger than the previous one
             * */
            if (sequence[i] > sequence[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prevIndex[i] = j;
                //prevIndex.push_back(j);
            }
        }
    }
    LSI=*max_element(dp,dp+n);//this variable takes the LSI to print it in the output file.
    int maxLengthIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[i] > dp[maxLengthIndex]) {
            maxLengthIndex = i;
        }
    }

    //Here we save the elements that configure the longest subsequence
    vector<int> longestSubsequence;
    while (maxLengthIndex != -1) {
        longestSubsequence.push_back(sequence[maxLengthIndex]);
        maxLengthIndex = prevIndex[maxLengthIndex];
    }

    reverse(longestSubsequence.begin(), longestSubsequence.end());

    return longestSubsequence;
}
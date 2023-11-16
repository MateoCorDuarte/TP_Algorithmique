//
// Created by corte on 11/16/2023.
//
#include <iostream>
#include "Pnt2.h"

vector<int> Ex2(const vector<int>& sequence, int n) {//const vector<int>& sequence
    //int n = sequence.size();
    //vector<int> dp(n, 1);//this vector saves the length of the subsequences
    prevIndex.resize(n, -1);//saves indexes of the previous elements in the subsequence
    int dp[n];

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
        LSI++;
    }

    reverse(longestSubsequence.begin(), longestSubsequence.end());

    return longestSubsequence;
}
vector<int> getVectorFromFile(){
    fstream myFile;
    myFile.open("");
    fstream inputFile("INPMONOSEQ.txt",ios::in);
    if(inputFile.is_open()) {
        //Here I was trying to use the files but there is a problem to read the files that I didn't had the
        //time to correct

        string lineInpt;
        getline(inputFile, lineInpt);
        //getting the range of the initial sequence
        long unsigned int n = std::stoul(lineInpt);
        vector<int> sequence(n);

        //getting the sequence
        getline(inputFile, lineInpt);
        string token;
        stringstream StringStream(lineInpt);

        while (getline(StringStream, token, ' ')) {
            // Store token string in the vector
            sequence.push_back(std::stoi(token));
        }
        if (0 < n) {
            for (long unsigned int index = sequence.size(); n < index; index--) {
                sequence.pop_back();
            }
        }
    }
    inputFile.close();
}

void writeFile(const vector<int> Answear){
    fstream output;
    output.open("OUTMONOSEQ.txt",ios::out);

    if(output.is_open()){
        output << LSI<< endl;

        for (long unsigned int index = 0; index < LSI; index++)
        {
            // Writing in the terminal the textFile information concerning the current student.
            // Adding 1 because mathematical table and informatical table are not the same.
            output << "a[" << prevIndex[index] + 1 << "] = " << Answear[index] << endl;
        }
        // Closing the file because we do not need it anymore.
        output.close();
    }
}

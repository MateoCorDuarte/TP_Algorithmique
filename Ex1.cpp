//
// Created by corte on 11/16/2023.
//

#include <iostream>
#include "Ex1.h"

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
            cout<<"/2 ";
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


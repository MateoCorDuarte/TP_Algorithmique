//
// Created by corte on 11/16/2023.
//

#ifndef TP_PNT2_H
#define TP_PNT2_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
extern vector<int> prevIndex(1, -1);
extern int LSI=0;
vector<int> Ex2(const vector<int>& sequence, int n);
vector<int> getVectorFromFile();
void writeFile(const vector<int> Answear);


#endif //TP_PNT2_H

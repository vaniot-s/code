//
// Created by vaniot on 18-11. Container With Most Water-27.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include "MyVector.h"
using namespace std;
int main(){
    for(int x=10;x<=26;x++){
        int n=pow(2,x);
        clock_t startTime=clock();
        MyVector<int> vec;
        for(int i=0;i<n;i++){
            vec.push_back(i);
        }
        for (int j = 0; j < n; ++j) {
            vec.pop_back();
        }
        clock_t endTime=clock();
        cout<<"2*n"<<":"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

    }  return 0;

}
//
// Created by vaniot on 2018/2/3.
//

#include <iostream>
#include <iterator>
using namespace std;
int main(int argc,char* argv[]){
    cout<<"cout: ";
    ostream_iterator<int>myout(cout,"\t"); //创建标准输出迭代器
    *myout=1;//只写入一次，不能读出
    myout++;//前置迭代指针
    *myout=2;
    myout++;
    *myout=3;
    return 0;
}
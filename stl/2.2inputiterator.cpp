//
// Created by vaniot on 2018/2/3.
//

/*
 * 输入迭代器
 *
 * 输出迭代器
 *
 */

#include <iostream>
#include <iterator>
using namespace std;
int main(int argc,char* argv[]){
    cout<<"input data like:11. Container With Most Water 22 33:";
    istream_iterator<int>a(cin);  //键盘输入流，并用istream_iterator枚举整型数据
    istream_iterator<int>b;       //建立输入流结束迭代器
    cout<<"istream:";
    while(1){
        cout<<*a<<endl; //输出整型数据->调用operator*()
        a++;            //迭代器指针指向下一个元素->调用operator++(int)
        if(a==b){      //迭代器等于结束迭代器，则->调用operator==
            break;
        }
    }
    return 0;
}
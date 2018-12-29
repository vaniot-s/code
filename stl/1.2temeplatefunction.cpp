//
// Created by vaniot on 2018/2/2.
//

/*
 *模板与操作符重载
 */

#include <cstring>
#include <iostream>
using namespace std;
/*比较大小的函数*/
template <class U,class  V>
bool MyGreater(U& u,V& v){
    return u>v;
};

class Student {
    char name[20]{};
    int grade;
public:
    Student(char name[],int grade){
        strcpy(this->name,name);
        this->grade=grade;
    }

    bool operator>(const int &value) const{
        return grade>value;
    }
};

int main(){
    Student STU(const_cast<char *>("Bob"), 90);
    int g=85;
    cout<<MyGreater(STU,g)<<endl;
    return 0;

}
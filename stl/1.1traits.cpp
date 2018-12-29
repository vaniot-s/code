//
// Created by vaniot on 2018/2/2.
//
/*
 *功能描述:把整型和或浮点型的和乘以相应的倍数输出
 */

#include <iostream>
using namespace std;
class CIntArray {
    int a[10]{};
public:
    CIntArray() {
        for (int i = 0; i < 10; i++) {
            a[i] = i + 1;
        }
    }
    int GetSum(int times){//整数倍
        int sum=0;
        for (int i : a) {
            sum+= i;
        }
        return sum*times;
    }
    int Get(int pos){
        return a[pos];
    }
};
class FloatArray {
    float f[10]{};
public:
    FloatArray() {
        for (int i = 1; i <=10; i++) {
            f[i-1] =1.0f/i;
        }
    }
    float GetSum(float times){//浮点数倍
      float sum=0.0f;
        for (float i : f) {
            sum+= i;
        }
        return sum*times;
    }
   float Get(int pos){
        return f[pos];
    }
};

/*
 *利用traits把代码中不同类型发生变化的片段拖出来用统一的接口来包装
 */
/*定义基础模板*/
template<class T>
class NumTraits{

};
/*模板特化*/
template<>
class NumTraits<CIntArray>{
public:
    typedef int resulttype;
    typedef int inputpara;
};

template <>
class NumTraits<FloatArray>{
public:
    typedef float  resulttype;
    typedef float inputpara;
};

//统一调用的模板类
template <class T>
class CApply{
public:
    typedef typename  NumTraits<T>::resulttype result; //typename后面的字符串为一个类型名称，而不是成员函数或者成员变量
    typedef  typename  NumTraits <T>::inputpara input;
    result GetSum(T& obj,input in){
        return obj.GetSum(in);
    }
};
int main(){
    CIntArray intArray;
    FloatArray floatArray;
    cout<<intArray.GetSum(3)<<endl;
    cout<<floatArray.GetSum(3.2)<<endl;
    //使用traits封装的接口
    CIntArray intArray1;
    FloatArray floatArray1;
    CApply<CIntArray>c1;
    CApply<FloatArray>c2;
    cout<<c1.GetSum(intArray1,3)<<endl;
    cout<<c2.GetSum(floatArray1,3.2f)<<endl;
    return 0;
}
//
// Created by vaniot on 18-11-25.
//

#ifndef NOTES_MYVECTOR_H
#define NOTES_MYVECTOR_H
#include "assert.h"
using namespace std;
template <typename T>
class MyVector{
private:
    T* data;
    int capacity; //容量
    int size;
    void resize(int newCapacity){ //私有的方法 o(n)
        assert(newCapacity>=size);
        T *newData=new T[newCapacity];
        for(int i=0;i<size;i++){
            newData[i]=data[i];
            delete[] data;
            data=newData;
            capacity=newCapacity;
        }
    }
public:
    MyVector(){
        data=new T[10];
        capacity=10;
        size=0;
    }
    ~ MyVector(){
        delete[] data;
    }

    void  push_back(T e){ //在元素末尾添加元素 o(1)
//        assert(size<capacity);
        if(size==capacity){
            resize(2*capacity);//重新分配空间
        }
        data[size++]=e;
    }
    T pop_back(){
        assert(size>0);
        T ret=data[size-1];
        size--;
        if (size==capacity/4)
        {
            resize(capacity/2);
        }
        return ret;
    }
};
#endif //NOTES_MYVECTOR_H

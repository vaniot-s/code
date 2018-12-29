//
// Created by vaniot on 2018/2/2.
//
/*
 *迭代器(指针):将容器与算法分离
 * 为数组容器，链表容器编制共同显示函数
 */

/*
 * 数组
 */

#include <iostream>
using namespace std;
template <class T>
class MyArray{
private:
    int m_nTotalSize; //数组总长度
    int m_nValidSize; //数组的有效长度
    T* m_pData; //数据
public:
    explicit MyArray(int nSize=3){
        m_pData=new T[nSize];
        m_nTotalSize= nSize;
        m_nValidSize=0;
    }
    void Add(T value){  //向m_pData添加数据
        if(m_nValidSize<m_nTotalSize) {//如果有效长度小于总长度
            m_pData[m_nValidSize]=value;  //赋值
            m_nValidSize++;  //有效长度加1
        }else{
            int i=0;
            auto * tmpData=new T[m_nTotalSize];//原始数据备份
            for (auto j = 0; j < m_nTotalSize ; j++) {
                tmpData[j]=m_pData[j];
            }
            delete []m_pData; //释放原始数据空间
            m_nTotalSize*=2;//原始数据空间重新分配
            m_pData=new T[m_nTotalSize];//传回备份数据
            for ( i = 0; i <m_nValidSize ; ++i) {
                m_pData[i]=tmpData[i];
            }
            delete []tmpData;
            m_pData[m_nValidSize]=value;
            m_nValidSize++;
        }
    }

    int GetSize(){  //返回数组的有效长度
        return m_nValidSize;
    }

    T Get(int pos){ //返回某一位置元素
        return  m_pData[pos];
    }
    T* Begin(){ //起始迭代指针
        return m_pData;
    }
    T* End(){ //结束迭代指针
        return m_pData+m_nValidSize;
    }
    virtual~MyArray(){   //析构函数
        if(m_pData!= nullptr){
            delete []m_pData;
            m_pData= nullptr;
        }
    }
};



//泛型显示函数
template <class Init>
void display(Init start,Init end){
    cout<<endl;
    for (Init mid = start; mid !=end; mid++) {
            cout<<*mid<<"\t";
    }
    cout<<endl;
}
//array的迭代器
template <class Init>
class ArrayIterator{
    Init* init;
public:
    explicit ArrayIterator(Init* init){
        this->init=init;
    }
    bool operator!=(ArrayIterator& it){
        return this->init!=it.init;
    }
    void operator++(int){
        init++;
    }
    Init operator*(){
        return *init;
    }
};


int main(){
    MyArray<int>arry;
    for (int i = 0; i <5 ; ++i) {
        arry.Add(i+1);
    }
    ArrayIterator<int>start(arry.Begin());
    ArrayIterator<int>end(arry.End());
    cout<<"Array elements:";
    display(start,end);
    return 0;
}

//
// Created by vaniot on 19-2-15.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_LIST_H
#define INTRODUCTION_TO_ALGORITHMS_LIST_H

#include "ListNode.h" //链表节点类
template <typename T> class List{//链表模板类
private:
    int  _size;//规模
    Posi(T) header;
    Posi(T) trailer;//头,尾哨兵
protected: /*内部函数*/
public: /*...析构函数,构造函数,只读接口,可写接口,遍历接口*/
    init();
};
template <typename T> void  List<T>::init(){//初始化,创建列表对象时统一调用
    header=new ListNode<T>; //哨兵头结点
    trailer=new ListNode<T>;//哨兵尾节点
    header->succ=trailer;header->pred=NULL;//互联
    trailer->pred=header;trailer->succ=NULL;//互联
    _size=0;//记录规模
}
template <typename T>
T List<T>::operator[](Rank r) const{ //循秩访问
    Posi(T) p=first();//从首节点出发
    while (0<r--) p=p->succ;//顺数第r个节点即是
    return p->data;//目标节点
} //任意节点的秩,即其前驱的总数
template <typename T>
Posi(T) List<T>::find(T const &e,int n,Posi(T) p)const { //顺序查找,O(n)
    while(0<n--){//从左向右,逐个将p的前驱与e对比
        if(e==(p=p->pred)->data) return p;//知道命中或范围越界
    }
    return NULL;//越出左边界,意味着查找失败
}//header 的存在使得处理更为简洁
template <typename T>//删除合法位置p处节点,返回其数值
T List<T>::remove(Posi(T) p){ //O(1)
    T e=p->data;
    p->pred->succ=p->succ;
    p->succ->pred=p->pred;
    delete p;
    _size--;
    return e;/返回备份数值
}

template <typename T> List<T>::~List()//链表析构
{
    clear();
    delete header;delete trailer; //清空链表,释放头,为哨兵节点
}
#endif //INTRODUCTION_TO_ALGORITHMS_LIST_H

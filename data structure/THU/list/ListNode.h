//
// Created by vaniot on 19-2-15.
//
//ListNode模板类
#ifndef INTRODUCTION_TO_ALGORITHMS_LIST_H
#define INTRODUCTION_TO_ALGORITHMS_LIST_H
#define Posi(T) ListNode<T>* //列表节点位置
template <typename T> //
struct ListNode{ //列表节点模板类(以双向链表形式实现)
    T data; //数值
    Posi(T) pred; //前驱
    Posi(T) succ;//后继
    ListNode(){} //对于header和trailer的构造
    ListNode(T e,Posi(T) p=NULL,Posi(T) s=NULL):data(e),pred(p),succ(p){} //默认构造器
    Posi(T ) insertAsPred(T const& e);//前插入
    Posi(T) inserAsSucc(T const& e);//后插入率
};


#endif //INTRODUCTION_TO_ALGORITHMS_LIST_H

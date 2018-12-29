//
// Created by vaniot on 2018/2/3.
//

#include <iostream>
using namespace std;

/*链表类初始化*/
template  <class  T>
class  MyLink{
public:
    struct Unit{
        T value;
        Unit* next;
    };
    //链表迭代器函数
    class LinkIterator{
        Unit* init;
    public:
        explicit LinkIterator(Unit* init){
            this->init=init;
        }
        bool operator!=(LinkIterator& it){
            return this->init!=it.init;
        }
        void operator++(int){
            init=init->next;
        }
        Unit operator*(){
            return *init;
        }
    };
    Unit* head; //链表头
    Unit* tail; //链表尾
    Unit* prev;
public:
    MyLink(){
        head=tail=prev= nullptr;
    }
    void Add(T &value){ //向链表中添加元素
        auto *u=new Unit();
        u->value=value;
        u->next= nullptr;
        if(head == nullptr){
            head=u;
            prev=u;
        }else{
            prev->next=u;
            prev=u;
        }
        tail=u->next;
    }
    Unit* Begin(){ //链表头指针
        return head;
    }
    Unit* End(){
        return tail;
    }
    virtual ~MyLink(){
        if(head!= nullptr){
            Unit* prev=head;
            Unit* next= nullptr;
            while(prev!=tail){
                next=prev->next;
                delete prev;
                prev=next;
            }
        }
    }
};
template <class T>
ostream& operator<<(ostream& os,MyLink<T>::Unit& s){
    os<<s.value;
    return os;
}
//泛型显示函数
template <class Init>
void display(Init start,Init end){
    cout<<endl;
    for (Init mid = start; mid !=end; mid++) {
        cout<<*mid<<"\t";
    }
    cout<<endl;
}

int main(){
    //链表类测试函数
    int m=0;
    MyLink<int> ml;
    for (int i = 0; i <5 ; ++i) {
        m=i+1;
        ml.Add(m);
    }
   MyLink<int>::LinkIterator Start= ml.Begin();
    MyLink<int>::LinkIterator  End=ml.End();
    display(Start,End);
    return 0;
}
//
// Created by vaniot on 18-12-9.
//
/**
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

 */



#ifndef NOTES_MIAN_H
#define NOTES_MIAN_H

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }
    ListNode *head = new ListNode(arr[0]); //创建头指针
    ListNode *curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

void printLinkedList(ListNode *head) {
    ListNode *curNode = head;
    while (curNode != NULL) {
        cout << curNode->val << " ->";
        curNode = curNode->next;//节点后移
    }
    cout << "NULL" << endl;
}

void deleteLinklist(ListNode *head) {
    ListNode* curNode=head;
    while(curNode!=NULL){
        ListNode* delNode=curNode;
        curNode=curNode->next;
        delete curNode;
    }
    return ;
}

class mian {
    ListNode *reverseBetween(ListNode *head, int m, int n) {

    }
};


#endif //NOTES_MIAN_H

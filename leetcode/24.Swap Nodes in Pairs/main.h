//
// Created by vaniot on 18-12-9.
//
/**
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

说明:

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class main {
public:
    //O(n)
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        while (p->next && p->next->next) {
            ListNode *node1 = p->next;
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;


            node2->next = node1;
            node1->next = next;

            p->next = node2;
            p = node1;
        }

        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};


#endif //NOTES_MAIN_H

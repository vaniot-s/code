//
// Created by vaniot on 18-12-9.
//
/**
 * 反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

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
    //改变指针的指向翻转,三个指针
    //时间复杂度O(n)
    //空间复杂度 O(1)
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = null;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


#endif //NOTES_MAIN_H

//
// Created by vaniot on 18-12-10.
//
/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

 */

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
public:
    //O(n)
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        assert(n >= 0);
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; ++i) {
            assert(q);
            q = q->next;
        }

        while (q != NULL) { //双指针滑动窗口
            p = p->next;
            q = q->next;
        }
        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        ListNode *retNode =dummyHead->next;
        return retNode;

    }
};


#endif //NOTES_MAIN_H

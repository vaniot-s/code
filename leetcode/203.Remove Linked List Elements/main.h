//
// Created by vaniot on 18-12-9.
//

/**
 * 删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

class main {
public:
    ListNode *removeElements(ListNode *head, int val) {
//        if (head == NULL) { //输入为空
//            return NULL;
//        }
//        while (head!=NULL&&head->val == val) { //头节点满足
//            ListNode *delNode = head;
//            head = delNode->next;
//            delete delNode;
//        }
//        if(head==NULL){ //头结点为空
//            return NULL;
//        }

// 虚拟的头结点
        ListNode *dummuHead = new ListNode(0);//虚拟的头结点
        dummyHead->next = head;
        ListNode* cur=dummuHead;
//        ListNode *cur = head;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                //删除cur->next
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};


#endif //NOTES_MAIN_H

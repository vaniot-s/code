//
// Created by vaniot on 19-3-9.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre=head;
        ListNode* point=head;
        while (point->next!=NULL){ //是否到达末尾指针
            if(point->val<x){
                if(point==head){
                    point=point->next;
                    pre=pre->next;
                    continue;
                }
                pre->val=point->val;
                point=point->next;
                pre=pre->next;
            }
        }
        return head;

        /***/
//        if(head == NULL|| head->next == NULL){
//            return head;
//        }
//        ListNode* cur=head;
//        while(cur->next!= nullptr){
//            if(cur->val==cur->next->val){
//                cur->next=cur->next->next;
//            }else{
//                cur=cur->next;
//            }
//        }
//        return head;
    }
};
#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H

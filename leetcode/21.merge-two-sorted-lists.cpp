/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.93%)
 * Total Accepted:    17.9K
 * Total Submissions: 36.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode **pTail = &head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                *pTail = l1;
                l1 = l1->next;
            } else {
                *pTail = l2;
                l2 = l2->next;
            }
            pTail = &(*pTail)->next;
        }
        *pTail = (l1 != NULL ? l1 : l2);
        return head;
    }
};

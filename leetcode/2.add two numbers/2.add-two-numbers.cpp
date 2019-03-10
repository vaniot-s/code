/*
 * [2] Add Two Numbers
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.10%)
 * Total Accepted:    38.5K
 * Total Submissions: 132.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *indexList = result, *p = l1, *q = l2;
        int carry = 0;
        while (p || q) {
            int a = p ? p->val : 0;
            int b = q ? q->val : 0;
            int sum = a + b + carry;

            carry = int(sum / 10);
            indexList->next = new ListNode(sum % 10);
            indexList = indexList->next;

            p = p ? p->next : p;
            q = q ? q->next : q;
        }

        if (carry > 0) {
            indexList->next = new ListNode(carry);
        }

        return result->next;
    }
};
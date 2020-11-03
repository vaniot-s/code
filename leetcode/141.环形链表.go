/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	m := make(map[*ListNode]int)
	for head != nil {
		if _, ok := m[head]; ok {
			return true
		}
		m[head] = 1
		head = head.Next
	}
	return false

}

// @lc code=end


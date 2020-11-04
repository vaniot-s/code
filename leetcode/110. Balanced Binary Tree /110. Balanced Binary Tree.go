package _10__Balanced_Binary_Tree_

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isBalanced(root.Left) &&
		math.Abs(height(root.Left)-height(root.Right)) < 2 && //两边最大深度差  大于2
		isBalanced(root.Right)

}

func height(root *TreeNode) float64 {
	if root == nil {
		return 0
	}
	return math.Max(height(root.Left), height(root.Right)) + 1
}

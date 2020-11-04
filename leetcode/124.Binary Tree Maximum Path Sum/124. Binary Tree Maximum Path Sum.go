package _24_Binary_Tree_Maximum_Path_Sum

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type ResultType struct {
	SinglePath int // 保存单边最大值
	MaxPath int // 保存最大值（单边或者两个单边+根的值）
}

func maxPathSum(root *TreeNode) int {
	result := helper(root)
	return result.MaxPath
}

func helper(root *TreeNode) ResultType {
	// check
	if root == nil {
		return ResultType{
			SinglePath: 0,
			MaxPath: -(1 << 31),
		}
	}
	// Divide
	left := helper(root.Left)
	right := helper(root.Right)

	// Conquer
	result := ResultType{}
	// 求单边最大值
	if left.SinglePath > right.SinglePath {
		result.SinglePath = max(left.SinglePath + root.Val, 0)
	} else {
		result.SinglePath = max(right.SinglePath + root.Val, 0)
	}
	// 求两边加根最大值
	maxPath := max(right.MaxPath, left.MaxPath)
	result.MaxPath = max(maxPath,left.SinglePath+right.SinglePath+root.Val)
	return result
}

func max(a,b int) int{
	if a>b {
		return a
	}
	return b
}
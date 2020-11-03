/*
 * @lc app=leetcode.cn id=42 lang=golang
 *
 * [42] 接雨水
 */
package _2_Trapping_Rain_Water

// @lc code=start
func trap(height []int) int {
	var result, left, right, maxl, maxr int
	right = len(height) - 1
	if left == right {
		return result
	}

	//双指针:退出条件right<=left
	for {
		if right <= left {
			return result
		}

		if height[left] < height[right] {
			if height[left] >= maxl {
				//设置左边最高柱子
				maxl = height[left]
			} else {
				//右边必定有柱子挡水，所以，遇到所有值小于等于leftMax的，全部加入水池
				result += maxl - height[left]
			}
			left++
		} else {
			if height[right] > maxr {
				//设置右边最高柱子
				maxr = height[right]
			} else {
				//左边必定有柱子挡水，所以，遇到所有值小于等于rightMax的，全部加入水池
				result += maxr - height[right]
			}
			right--
		}
	}
}

// @lc code=end

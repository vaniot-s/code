/*
 * @lc app=leetcode.cn id=169 lang=golang
 *
 * [169] 多数元素
 */

// @lc code=start
func majorityElement(nums []int) int {
if len(nums)<3{
	return nums[0]
}

kv:=map[int]int

for i := 0; i < len(nums); i++ {
	kv[nums[i]]+=1	
}

max,res int

for k, v := range kv {
	if v>max{
		res=k
	}
}
return res
}
// @lc code=end


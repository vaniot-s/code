package _28__Maximum_Product_of_Three_Numbers

import (
	"math"
	"sort"
)

func maximumProduct(nums []int) int {
	sort.Ints(nums)
	return int(math.Max(float64(nums[len(nums)-1]*nums[len(nums)-2]*nums[len(nums)-3]), float64(nums[len(nums)-1]*nums[0]*nums[1])))
}
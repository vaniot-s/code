package _6_remove_duplicate_from_sorted_array

func removeDuplicates(nums []int) int {
	if len(nums)<=1 {
		return len(nums)
	}

	k:=0 //指向排序元素中第一次出现的位置
	for i := 1; i < len(nums) ; i++ {
		if nums[i] != nums[k]{
			k++
			nums[k]=nums[i]
		}
	}
	return k+1
}


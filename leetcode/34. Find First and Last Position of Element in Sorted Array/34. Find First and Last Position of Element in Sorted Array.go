package _4__Find_First_and_Last_Position_of_Element_in_Sorted_Array

func searchRange(nums []int, target int) []int {
	if len(nums)==0 {
		return []int{-1,-1}
	}
	lower := lower_bound(nums, target)
	upper := upper_bound(nums, target) - 1 // 这里需要减1位
	if lower ==len(nums) || nums[lower] != target {
		return []int{-1, -1}
	}
	return []int{lower, upper}
}

func lower_bound(nums []int,target int) int{
	l:=0
	r:=len(nums)
	mid:=0
	for l<r{
		mid=(l+r)/2
		if nums[mid]>=target{
			r=mid
		}else{
			l=mid+1
		}
	}
	return l
}

func upper_bound(nums []int,target int) int{
	l:=0
	r:=len(nums)
	mid:=0
	for l<r{
		mid=(l+r)/2
		if nums[mid]>target{
			r=mid
		}else{
			l=mid+1
		}
	}
	return l
}


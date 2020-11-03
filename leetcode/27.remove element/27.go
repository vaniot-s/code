package _7_remove_element

func removeElement(nums []int, val int) int {
	//思路：将所有的非指定元素，移动到左边
	k:=0 //始终指向不为指定元素的下一个位置
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[k]=nums[i]
			k++
		}
	}
	return k
}
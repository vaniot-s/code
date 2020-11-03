package _83__Move_Zeroes

func moveZeroes(nums []int)  {
	//思路:将所有的非０元素移动到左边
	k:=0 //维护定义，k始终指向不为零位置的下一个位置
	for i:=0;i<len(nums);i++{
		if nums[i]!=0{
			nums[k]=nums[i]
			k++
		}
	}
	for i:=k;i<len(nums);i++{
		nums[i]=0
	}
}
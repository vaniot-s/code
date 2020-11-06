package _60__Single_Number_III_

func singleNumber(nums []int) []int {
	m:=make(map[int]int)
	for _,v:=range nums{
		m[v]+=1
	}
	res:=make([]int,0)
	for k,v:=range m {
		if(v==1) {
			res= append(res,k)
		}
	}
	return res
}

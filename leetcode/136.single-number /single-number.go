package _36_single_number_

func singleNumber(nums []int) int {

	m:=make(map[int]int)
	for _,v:=range nums{
		m[v]+=1
	}
	res:=0
	for k,v:=range m {
		if(v==1) {
			res= k
		}
	}
	return res
}

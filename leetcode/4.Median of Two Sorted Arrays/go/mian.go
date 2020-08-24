package main

import (
	"fmt"
	"math"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// 1.先合并在查找O(m＋n)
	//　2.使用二分法

	//　中间值的特点左边均小，右边的值均大与
	var a,b =nums1,nums2
	if len(nums1)>len(nums2){
		a,b=nums2,nums1
	}
	low,high,k,aMid,bMid:=0,len(a),(len(a)+len(b)+1)>>1,0,0

	for low<=high  {
		aMid=low+(high-low)>>1 // a的中间位置
		bMid=k-aMid// b的中间位置
		if aMid>0&&a[aMid-1]>b[bMid] { //　a的中间位置偏右
		  high=aMid-1
		}else if aMid!=len(a)&& a[aMid]<b[bMid-1] { // 偏左右移
	      low=aMid+1
		}else {
			break
		}
	}

	midLeft,midRight:=0,0
	if aMid ==0{
		midLeft=b[bMid-1]
	}else if bMid==0 {
		midLeft=a[aMid-1]
	}else{
		midLeft=int(math.Max(float64(a[aMid-1]),float64(b[bMid-1])))
	}

	if (len(a)+len(b))&1 == 1 {
		return float64(midLeft)
	}
	if aMid == len(a) {
		midRight = b[bMid]
	} else if bMid == len(b) {
		midRight = a[aMid]
	} else {
		midRight = int(math.Min(float64(a[aMid-1]),float64(b[bMid-1])))
	}
	return float64(midLeft+midRight) / 2
}
func main() {
	nums1 := []int{}
	nums2 := []int{2}

	fmt.Println("",findMedianSortedArrays(nums1,nums2))
}

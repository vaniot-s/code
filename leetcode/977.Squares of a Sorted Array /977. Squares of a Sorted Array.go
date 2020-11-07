package _77_Squares_of_a_Sorted_Array_

import "sort"

func sortedSquares(A []int) []int {
	squares := make(map[int]int, 0)
	for _, val := range A {
		squares[val*val] += 1
	}
	 results:=make([]int,0)
	for index, times := range squares {
		for i := 0; i < times; i++ {
			results = append(results, index)
		}
	}
	sort.Ints(results)
	return results
}

package _67_Transpose_Matrix

func transpose(A [][]int) [][]int {
	if len(A) == 0 {
		return A
	}

	rlength := len(A)                // 转置矩阵的长
	rwidth := len(A[0])              // 转置矩阵的宽
	results := make([][]int, rwidth) // 返回转置矩阵
	for i := 0; i < rwidth; i++ {    // 分配二维矩阵空间
		results[i] = make([]int, rlength)
	}

	for r, row := range A { // 遍历当前矩阵
		for c, _ := range row {
			results[c][r] = A[r][c]
		}
	}
	return results

}
//
// Created by kuili on 2020/1/9.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H

/*
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
class main {
public:
    int minPathSum(vector<vector<int>>& grid){
        // 递归的特征：
        //  1.重复性的计算
        //  2.下一步依赖于上一步的计算结果
        // dp:
        //  1.递归的逆推
        //  2.每一步都是最优的解

        //思路:由右下角入手,两个
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H

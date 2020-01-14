//
// Created by vaniot on 2020/1/7.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_MAIN_H
#define INTRODUCTION_TO_ALGORITHMS_MAIN_H

/**
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class main {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     // 递归解法由上自下　结果为n*(n-1)的最小值
     // dp由下到上最多为o(n) 的额外空间
     //层数
        vector<int> res(triangle.back());
        for (int i =triangle.size()-2; 0<=i ;i--) { //　退出条件
            for (int j = 0; j <=i ; ++j) {
                res[j]= min(res[j],res[j+1]) + triangle[i][j]; //由底层向顶层
            }
        }
        return res[0];
    }
};


#endif //INTRODUCTION_TO_ALGORITHMS_MAIN_H

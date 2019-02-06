//
// Created by vaniot on 18-12-6.
//
/*
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
//使用查找表
*/
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class main {
public:
    //时间复杂度o(n^2)
    //空间复杂度 O(n)
    int numberOfBoomerangs(vector<pair<int, int> & points) { //存储数据段
        int res = 0; //记录三元组
        for (int i = 0; i < points.size(); ++i) { //枢纽点
            unordered_map<int, int> record; //查找表记距离及频次
            for (int j = 0; j < points.size(); ++j) {
                if (j != i) {
                    record[dis(points[i], points[j])]++; //查找表
                }
            }

            //遍历查找表
            for (unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
                if (iter->second >= 2) {
                    res += (iter->second) * (iter->second - 1);
                }
            }
        }
        return res;
    }

private:
    int dis(const pair<int, int> &pa, const pair<int, int> &pb) { //距离的平方,避免浮点误差
        return (pa.first - pb.first) * (pa.first - pb.first) + (pa.second - pb.second) * (pa.second - pb.second); //注意越界
    }
};


#endif //NOTES_MAIN_H

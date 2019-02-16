//
// Created by vaniot on 18-12-11. Container With Most Water.
//
/**
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.

示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

 问题建模:->图论问题
 从N到0,每个数字表示一个节点
 如果两个数字X到y相差一个完全平方数,则连接一条边,
 ->无权图(广度优先) 在无权图中从n到0的连接的最短路径


 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

#include<iostream>
#include<vector>
#include <queue>
#include <stdexcept>

class main {
public:
    int numSquares(int n) {
        queue <pair<int, int>> q;
        q.push(make_pair(n, 0));
        vector<bool> visited(n+1,false);
        visited[n]=true;
        while (!q.empty()) {
           int num=q.front().first;
           int step=q.front().second;
           q.pop();

            for (int i = 0; ; ++i) {
                int a=numi*i;
                if(a<0){
                    break;
                }
                if (a== 0) {
                    return step+1;
                }
                if (!visited[a]) {
                    q.push(make_pair(a, step + 1));
                    visited[a]=true;
                }
            }
        }
        throw invalid_argument("No Solution,");
    }
};


#endif //NOTES_MAIN_H

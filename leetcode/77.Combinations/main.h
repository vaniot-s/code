//
// Created by vaniot on 18-12-17.
//
/**
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


 */
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


class main {
private:
    vector<vector<int>> res;
    /**
     * 求解C(n,k),当前已经找到的组合存储在C中,需要从start开始搜索新的元素
     * @param n
     * @param k
     * @param start
     * @param c
     */
    void generateCombinations(int n,int k,int start,vector<int> &c){
        if (c.size()==k){ //递归的终止条件
            res.push_back(c);
            return;
        }

//        for (int i = start; i <=n ; ++i) { //递归的实现
//            c.push_back(i);
//            generateCombinations(n,k,i+1,c);
//            c.pop_back();
//        }

         //还有k-c.size()个空位->[i...n]中至少要有k-c.size()个元素
        for (int i = start; i <=n-(k-c.size())+1; ++i) { //递归回溯剪枝
            c.push_back(i);
            generateCombinations(n,k,i+1,c);
            c.pop_back();
        }
        return;
    }
public:
    vector <vector<int>> combine(int n, int k) {
        res.clear();
        if(n<=0||k<=0||k>n){
            return res;
        }
        vector<int> c;
        generateCombinations(n,k,1,c);
        return res;
    }
};


#endif //NOTES_MAIN_H

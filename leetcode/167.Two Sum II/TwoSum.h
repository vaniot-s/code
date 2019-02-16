//
// Created by vaniot on 18-12-1.
//

/*给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:

输入: numbers = [2, 7, 11. Container With Most Water, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */


#ifndef NOTES_TWOSUM_H
#define NOTES_TWOSUM_H

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

class TwoSum {

    //1.直接的方法,暴力解法,双层遍历o(n^2) 10000内

    //2. 数组的性质有序---二分搜索 O(nlogn)
     //i指向当前的位置,在之后的位置中使用二分查找值

    //3,双索引=>两个数一定是一左一右的存在->对撞指针.有序--从两端找相加,对撞指针,双索引
public :
    vector(int) twoSum(vector<int>& numbers,int target){ //O(n)
    assert(numbers.size()>=2);//小于
    int l=0,r=numbers.size()-1;
    while(l<r){
        if (numbers[l]+numbers[r]==target){
            int res[2]={l+1,r+1};
            return vector<int> (res,res+2);
        }else if(numbers[l]+numbers[r]<target){ //小于左索引增加
            l++;
        }else{ //大于右指针减少
            r--;
        }
    }
    throw invalid_argument("The input has no solution");
}
};


#endif //NOTES_TWOSUM_H

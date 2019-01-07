//
// Created by vaniot on 18-12-1.
//
/**
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]

进阶：
    一个直观的解决方案是使用计数排序的两趟扫描算法。
    首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。  ---计数排序
    你能想出一个仅使用常数空间的一趟扫描算法吗？
 */

#ifndef NOTES_SORTCOLORS_H
#define NOTES_SORTCOLORS_H
using namespace std;
//计数排序
class SortColors {
public:
    //时间复杂度 O(n)
    //空间复杂度 O(k) k为元素范围
    void sortColors(vector<int>& nums){ //计数排序思路
        int count[3]={0}; //扫描三个元素出现的概率,记录存放0,1,2元素的频率
        for(int i=0;i<nums.size();i++){
            assert(nums[i]>=0&&nums[i]<=2); //容错处理 tip,数组越界
            count[nums[i]]++; //记录元素
        }
        //将元素放回值
        int index=0;
        for(int i=0;i<count[0];i++){
            nums[index++]=0;
        }
        for(int i=0;i<count[1];i++){
            nums[index++]=0;
        }
        for(int i=0;i<count[2];i++){
            nums[index++]=0;
        }
    }

    //时间复杂度 O(n)
    //空间复杂度 O(1)
    void sortColors1(vector<int>&nums){ //数组拍好序后为[0...1....2...]=>三路快排思路:将元素分为三个部分:>v ==v  v<
        int zero=-1;//nums[0...zero]==0 zero指向0的最后一个元素
        int two=nums.size();//nums[two..n-1]==2 two指向第一个2
        for (int i = 0; i <two ; ) { //i遍历元素,在过程中维护循环的不变量
            if(nums[i]==1){
                i++;
            }else if(nums[i]==2){
                swap(nums[i],nums[--two]); //交换元素
            }else{
                assert(nums[i]==0);
                zero++;
                swap(nums[zero],nums[i]); //交换为0的元素
                i++;
            }
        }
    }
};

#endif //NOTES_SORTCOLORS_H

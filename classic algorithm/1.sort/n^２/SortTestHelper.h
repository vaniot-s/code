//
// Created by kuili on 2020/2/5.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_SORTTESTHELPER_H
#define INTRODUCTION_TO_ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespacestd;

// 排序的辅助函数，用于生成测试用例
namespace SortTestHelper {

    /**
     * 生成有Ｎ个元素的随机数组，每个元素的随机范围为[rangeL，RangeR]
     * @param n
     * @param rangeL
     * @param rangeR
     * @return
     */
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR)
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;//
        }
        return arr;
    }

    /**
     * 输出
     * @tparam T
     * @param arr
     * @param n
     */
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i <; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;

        return;
    }

    /**
     * 测试排序算法的性能，时间
     * @tparam T
     * @param sortName　排序算法名
     * @param sort　排序算法本身，函数指针＊sort,函数参数　T[],int
     * @param arr　测试数组
     * @param n　数组长度
     */
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << " s"
             << endl; //CLOCKS_PER_SEC每秒钟运行时钟周期的个数
    }

    /**
     * 判断是否已经排序
     * @tparam T
     * @param arr
     * @param n
     * @return
     */
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
            return true;
        }
    }

    /**
     * 拷贝整型数组
     * @param a
     * @param n
     * @return
     */
    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

    /**
     *　近乎有序的数组
     * @param n
     * @param swapTimes
     * @return
     */
    int *generateNearlyOrderedArray(int n, int swapTimes){
        int *arr=new int[n];
        for (int i = 0; i <n ; ++i) {
            arr[i]=i;
        }
        srand(time(NULL));
        for (int j = 0; j <swapTimes ; ++j) {
            int posx=rand()%n;
            int posy=rand()%n;
            swap(arr[posx],arr[posy]);
        }
    }
}
#endif //INTRODUCTION_TO_ALGORITHMS_SORTTESTHELPER_H

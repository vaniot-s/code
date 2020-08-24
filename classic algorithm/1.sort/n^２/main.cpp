#include <iostream>
#include <algorithm>
#include "student.h"
#include "SortTestHelper.h"

using namespace std;

/**
 * 选择排序　　n^2
 * 模板　泛型
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void selectSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        //在[i,n)区间找到最小值
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            swap(arr[i], arr[minIndex])
        }
    }
}

/**
 * 插入排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        //arr[i]合适的插入位置
        for (int j = i j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                swap([j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

/**
 * 插入优化
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertSort2(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        //arr[i]合适的插入位置
        T e = arr[i];
        int j; //j保存元素e应该ｉ插入的位置
        for (j = i; j > 0; --j) {
            arr[j] = arr[j - 1]
        }
        arr[j] = e;
    }
}
// 衍生希儿排序
int main() {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectSort(a, 10)
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    float b[4] = {4.4, 3.3, 2, 2, 1.1};
    selectSort(b, 4);
    for (int j = 0; j < 4; ++j) {
        cout << b[j] << " ";
    }
    cout << endl;
    string c[4] = {"D", "B", "C", "A"};
    selectSort(c, 4);
    for (int k = 0; k < 4; ++k) {
        cout << c[k] << " ";
    }
    cout << endl;

    Student d[4] = {{"d", 90},
                    {"C", 100},
                    {"B", 95}};
    selectSort(d, 4);
    for (int k = 0; k < 4; ++k) {
        cout << c[k] << " ";
    }
    cout << endl;

    int n = 10000
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n)
    int *arr3 = SortTestHelper::copyIntArray(arr, n)
//    selectSort(arr, n);
//    SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Select Sort", selectSort, arr, n);
    SortTestHelper::testSort("insert sort", insertSort, arr2, n);
    SortTestHelper::testSort("insert sort2", insertSort2, arr3, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;


    int *ar4 = SortTestHelper::generateNearlyOrderedArray(n, 0, 10);
    int *arr5 = SortTestHelper::copyIntArray(arr, n)
    int *arr6 = SortTestHelper::copyIntArray(arr, n)

    SortTestHelper::testSort("Select Sort", selectSort, arr4, n);
    SortTestHelper::testSort("insert sort", insertSort, arr5, n);
    SortTestHelper::testSort("insert sort2", insertSort2, arr6, n);
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    return 0;
}
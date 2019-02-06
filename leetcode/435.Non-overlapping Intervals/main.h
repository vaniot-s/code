//
// Created by vaniot on 18-12-23.
//
/**
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

    可以认为区间的终点总是大于它的起点。
    区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
->最多保留多少个区间
先排序->判读不重复

 */

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &a, const Interval &b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

class main {
public:
    int eraseOverlapIntervals(vector <Interval> &intervals) {
//        if (intervals.size() == 0) {
//            return 0;
//        }
//        sort(intervals.begin(), intervals.end(), compare);
        //dp
        //memo[i]表示使用intervals[0..i]的区间能构成最长不重叠区间序列
//        vector<int> memo(intervals.size(),1);
//        for (int i = 1; i < intervals.size(); ++i) { //dp
//            //memo[i]
//            for (int j = 0; j <i ; ++j) {
//                if (intervals[i].start>=intervals[j].end){
//                    memo[i]=max(memo[i],1+memo[j]);
//                }
//            }
//        }
//
//        int res=0;
//        for (int k = 0; k < memo.size(); ++k) {
//            res=max(res,memo[k]);
//        }
//        return intervals.size()-res;
//  贪心算法
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int res=1;
        int pre=0;
        for (int i = 0; i < intervals.size(); ++i) {
            if(intervals[i].start>=intervals[pre].end){
                res++;
                pre=i;
            } else if(intervals[i].end < intervals[pre].end)
                pre = i;
        }
        return intervals.size()-res;
    }
};


#endif //NOTES_MAIN_H

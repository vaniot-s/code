//
// Created by vaniot on 18-12-11.
//

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

/*
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:

输入: nums = [1], k = 1
输出: [1]

说明：

    你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
    你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * */
class main {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /**
         *  给定非空数组,返回前K个出现频率最高的元素
         *  维护含有k个元素的优先队列,如果遍历的元素比队列中的最小频率元素的频率高则取出队列中最小频率的元素,将
         *  新元素入队,队列中剩下的即是前k个出现频率最高的元素.
         */
         assert(k>0);//输入合法
         unordered_map<int,int> freq; //统计每个元素出现的频率
        for (int i = 0; i <nums.size() ; ++i) {
            freq[nums[i]]++;
        }
        assert(k<=freq.size());
        //扫描freq,维护当前出现频率最高的k个元素
        //在优先队列中,按照频率排序,所以数据对是(频率,元素)的形式
        priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>>pq;
        for (unordered_map<int,int>::iterator_iter=freq.begin();iter!=freq.end();iter++) {
            if(pq.size()==k){
                if(iter->second>pq.top().first){ //取代优先队列中频率最小的元素
                    pq.pop();
                    pq.push(make_pair(iter->second.iter->first));
                }
            }else{
                pq.push(make_pair(iter->second.iter->first));
            }
        }
        vector<int> res;
        while(1pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};


#endif //NOTES_MAIN_H

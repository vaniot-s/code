//
// Created by vaniot on 18-9-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

template <typename T>
void insert_sort(std::vector<T>&V){
    for (size_t i=1;i<V.size();++i){
        auto key=V[i];
        auto position=std::lower_bound(V.begin(),V.begin()+i,key); //二分查找
        for (auto iter = V.begin()+i;iter >position ; -- iter) {
            *iter=*(iter-1);
            *position=key;
        }
    }
}

int main(){
    double start_t,end_t;//计时器

    //内存分配计时开始
    start_t=clock();
    std::vector<double> V(900000);//90万数据
    //内存分布计时结束输出时间
    end_t=clock();
    std::cout<<(end_t-start_t)/(CLOCKS_PER_SEC*60)<<"minutes"<<std::endl;

    //数据赋值计时
    start_t=clock();
    //利用随机数生成0.0到0.1之间的实数
    std::default_random_engine generator(time(NULL));
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    for (size_t i= 0; i<V.size() ; ++i) {
        V[i]=distribution(generator);
    }
    //数据赋值计时结束并输出时间

    end_t=clock();
    std::cout<<(end_t-start_t)/(CLOCKS_PER_SEC*60)<<"minutes"<<std::endl;

    //排序计时开始
    start_t=clock();
    //插入排序
    insert_sort(V);
    //排序计时结束并输出时间
    end_t=clock();
    std::cout<<(end_t-start_t)/(CLOCKS_PER_SEC*60)<<"minutes"<<std::endl;
    return 0;
}
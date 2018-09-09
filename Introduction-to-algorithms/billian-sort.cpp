#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
/**
 *
 *随意产生10亿数据并排序
 * */
int main(int argc, char const *argv[])
{
    /* code */
    // 计时器
    double start_t=clock();

    std::vector<double> V(100000000); //十亿数据
    // 随机生成0.0～1.0之间的实数
    std::default_random_engine generator(time(NULL));
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    for(size_t i=0;i<V.size();++i){
        V[i]=distribution(generator);
    }
    sort(V.begin(),V.end());
    double end_t=clock();
    std::cout<<(end_t-start_t)/(CLOCKS_PER_SEC*60)<<"minutes"<<std::endl;
    return 0;
}

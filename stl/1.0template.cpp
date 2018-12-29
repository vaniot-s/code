//
// Created by vaniot on 2018/1/30.
//
# include<cstdio>
template<class T>

class MyArray{
private:
    int m_nTotalSize; //数组总长度
    int m_nValidSize; //数组的有效长度
    T* m_pData; //数据
public:
    explicit MyArray(int nSize=3){
      m_pData=new T[nSize];
      m_nTotalSize= nSize;
      m_nValidSize=0;
  }
    void Add(T value){  //向m_pData添加数据
        if(m_nValidSize<m_nTotalSize) {//如果有效长度小于总长度
            m_pData[m_nValidSize]=value;  //赋值
            m_nValidSize++;  //有效长度加1
        }else{
            int i=0;
            auto * tmpData=new T[m_nTotalSize];//原始数据备份
            for (auto j = 0; j < m_nTotalSize ; j++) {
                tmpData[j]=m_pData[j];
            }
            delete []m_pData; //释放原始数据空间
            m_nTotalSize*=2;//原始数据空间重新分配
            m_pData=new T[m_nTotalSize];//传回备份数据
            for ( i = 0; i <m_nValidSize ; ++i) {
                m_pData[i]=tmpData[i];
            }
            delete []tmpData;
            m_pData[m_nValidSize]=value;
            m_nValidSize++;
        }
    }

    int GetSize(){  //返回数组的有效长度
        return m_nValidSize;
    }

    T Get(int pos){ //返回某一位置元素
        return  m_pData[pos];
    }

    virtual~MyArray(){   //析构函数
        if(m_pData!= nullptr){
            delete []m_pData;
            m_pData= nullptr;
        }
    }
};

int main(){
    MyArray<int>obj;
    obj.Add(1);
    obj.Add(2);
    obj.Add(3);
    obj.Add(4);
    for ( int i = 0; i <obj.GetSize() ; i++) {
        printf("%d\n",obj.Get(i));
    }
    return 0;
}

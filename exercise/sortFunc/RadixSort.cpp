//
// Created by vera on 19-3-31.
//
#include<iostream>
#include<vector>

using namespace std;


//基数排序
//通过序列中各个元素的值，对排序的N个元素进行若干趟的“分配”与“回收”
//分配：将vec[i]元素取出，首先对其各位上的数字进行排序，根据数字分配到与之相同的桶中
//收集：当序列中的所有元素都分配到了对应的桶中，再按照顺序依次将桶中的元素收集形成新的一个待排序序列vec
//对新生成的序列重复执行分配（依次对元素的十位，百位...直到最高位）和收集

void countSort(vector<int>& vec,int exp) {
    vector<int> range(10,0);

    int length=vec.size();
    vector<int> tmpVec(length,0);

    for(int i=0;i<length;++i) {
        range[(vec[i]/exp)%10]++;
    }

    for(int i=1;i<range.size();++i) {
        range[i]+=range[i-1];//统计截止到该桶，所有的桶中一共有多少个数字
    }

    for(int i=length-1;i>=0;--i) {
        tmpVec[range[(vec[i]/exp)%10]-1]=vec[i];//
        range[(vec[i]/exp)%10]--;
    }
    vec=tmpVec;
}

void radixSort(vector<int>& vec) {
    int length=vec.size();
    int max=-1;
    for(int i=0;i<length;++i) {//提取出最大值
        if(vec[i]>max)
            max=vec[i];
    }

    //提取每一位并进行比较，位数不足的高位补0
    for(int exp=1;max/exp>0;exp*=10){
        countSort(vec,exp);
    }

}

int main() {
    int a[10]={53,3,542,748,14,214,154,63,616,589};

    vector<int> vec(a,a+10);
    radixSort(vec);

    for(int i=0;i<vec.size();++i) {
        cout<<vec[i]<<"   ";
    }

    cout<<endl;
    return 0;
}

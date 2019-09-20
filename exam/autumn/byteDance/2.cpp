//
// Created by vera on 19-9-15.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    return a.first<b.first; //从小到大
}

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> vec(n); //<时间,个数>
    int a, b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        vec[i]=make_pair(a, b);
    }

    sort(vec.begin(), vec.end(), cmp);

    long long maxSize=0;
    long long endTime=0;
    for(int i=0; i<n; i++){
        //计算这批文件到来时的堆积量
        long long tempSize=0;
        if(endTime<vec[i].first){
            tempSize=vec[i].second;
        }else{
            tempSize=endTime-vec[i].first+vec[i].second;
        }
        if(tempSize>maxSize){
            maxSize=tempSize;
        }
        //计算这批文件执行完的时间
        if(endTime<vec[i].first){
            endTime=vec[i].first+vec[i].second;
        }else{
            endTime+=vec[i].second;
        }
    }
    cout<<endTime<<" "<<maxSize;
    return 0;
}

//
// Created by vera on 19-4-3.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(long long a, long long b){
    return a>b; //从大到小
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> vec;
    for(int i=0; i<n; i++){
        long long tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    for(int i=0; i<m; i++){
        long long t, x;
        cin>>t>>x;
        if(t==0){//升序
            sort(vec.begin(), vec.begin()+x);
        }else if(t==1){//降序
            sort(vec.begin(), vec.begin()+x, cmp);
        }
    }
    for(long long item : vec){
        cout<<item<<" ";
    }
    return 0;
}
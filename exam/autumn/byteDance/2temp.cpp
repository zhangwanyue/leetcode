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
//    int n;
//    cin>>n;
//    vector<pair<long long, long long>> vec(n);
//    int a, b;
//    for(int i=0; i<n; i++){
//        cin>>a>>b;
//        vec[i]=make_pair(a, b);
//    }

    vector<pair<long long, long long>> vec(3);
    vec[0]=make_pair(2, 12);
    vec[1]=make_pair(3, 13);
    vec[2]=make_pair(1, 11);

    sort(vec.begin(), vec.end(), cmp);
    for(int i=0; i<3; i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }

}
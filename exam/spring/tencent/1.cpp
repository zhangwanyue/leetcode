//
// Created by vera on 19-3-10
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int a;
    vector<int> checkPoint;
    int n;
    cin>>n>>a;
    int input;
    for(int i=0; i<n; i++){
        cin>>input;
        checkPoint.push_back(input);
    }
    sort(checkPoint.begin(), checkPoint.end());
    if(n==1){
        cout<<0;
    }
    if(a<checkPoint[0]){
        cout<<(checkPoint[n-2]-a);
    }else if(a>checkPoint[n-1]){
        cout<<(a-checkPoint[1]);
    }else{
        int distance1 = (a-checkPoint[0])+(checkPoint[n-2]-checkPoint[0]);
        int distance2 = (checkPoint[n-1]-a)+(checkPoint[n-1]-checkPoint[1]);
        cout<<(distance1<distance2?distance1:distance2);
    }
}
//测试输入：
//3 10
//1 7 12
//测试输出：
//7
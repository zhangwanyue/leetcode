//
// Created by vera on 19-4-3.
//
#include <vector>
#include <iostream>
using namespace std;

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

int main() {
    int n;
    cin>>n;
//    scanf("%d", &n);
    vector<int> vec;
    long long min = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
//        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    for(int i=0; i<vec.size(); i++){
        long long sum = 0;
        for(int j=0; j<vec.size();j++){
            sum += abs(vec[(i+j)%vec.size()] -j-1);
        }
        if(sum<min || min==0){
            min = sum;
        }
    }
    cout<<min;
//    printf("%d", min);
    return 0;
}
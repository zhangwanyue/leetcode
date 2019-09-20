//
// Created by vera on 19-8-9.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    n-=3;
    vector<int> vec(n+1);
    vec[0]=1;
    vec[1]=1;
    vec[2]=1;
    vec[3]=2;
    if(n<=3){
        cout<<vec[n]*2;
        return 0;
    }
    for(int i=4; i<=n; i++){
       vec[i]=vec[i-3] + vec[i-1];
    }
    cout<<2*vec[n];
    return 0;
}


//
// Created by vera on 19-8-10.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int dp[n];
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    int len = 1;
    dp[0] = vec[0];
    for (int i = 1; i < n; i++)
    {
        int pos = lower_bound(dp, dp + len, vec[i]) - dp;
        dp[pos] = vec[i];
        len = max(len, pos + 1);
    }
    cout<<len;
}
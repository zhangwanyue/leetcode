//
// Created by vera on 18-8-19.
//
# include <iostream>
# include <vector>
# include <climits>

using namespace std;

/**
 * 从上向下计算
 */
#if 1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty() || triangle[0].empty()){
            return 0;
        }
        int column = triangle.size();
        int row = triangle[column-1].size();
        vector<int> dp(row, 0);
        dp[0] = triangle[0][0];
        vector<int> temp(dp);
        int prior, mid, rear;
        for(int i=1; i<column; i++){
            for(int j=0; j<triangle[i].size(); j++){
                prior = INT_MAX, rear = INT_MAX;
                if(j-1>=0) prior = temp[j-1];
                if(j<triangle[i-1].size()) rear = temp[j];
                dp[j] = min(prior, rear) + triangle[i][j];
            }
            temp = dp;
        }
        int minTotal = dp[0];
        for(int i=1; i<column; i++){
            minTotal = min(minTotal, dp[i]);
        }
        return minTotal;
    }
};
#endif

/**
 * 从下往上计算
 */
#if 0
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(triangle[n-1]);
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        return dp[0];
    }
};
#endif

int main(){
    vector<vector<int> > triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
//    vector<vector<int> > triangle ;
//    vector<vector<int> > triangle = {};
//    vector<vector<int> > triangle = {{}};
    cout<<(new Solution)->minimumTotal(triangle)<<endl;
}

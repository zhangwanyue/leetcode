//
// Created by vera on 18-8-16.
//
# include<iostream>
# include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        //初始化
        dp[0][0]=grid[0][0];
        for(int i=1; i<row; i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1; i<column; i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        //dp
        for(int i=1; i<row; i++){
            for(int j=1; j<column; j++){
                dp[i][j]= min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[row-1][column-1];
    }
};

int main(){
    vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1},{1,1,1}};
    cout<<(new Solution)->minPathSum(grid);
}
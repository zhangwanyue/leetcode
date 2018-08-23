//
// Created by vera on 18-8-19.
//

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * 用滚动数组来做吧，可以节省空间
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        vector<int> steps;
        steps.push_back(grid[0][0]);
        for(int i=1; i<col; i++){
            steps.push_back(steps[i-1]+grid[0][i]);
        }
        for (int i = 1; i < row; i++) {
            steps[0] = steps[0] + grid[i][0];
            for (int j = 1; j < col; j++) {
                steps[j] = min(steps[j], steps[j - 1]) + grid[i][j];
            }
        }
        return steps[col - 1];
    }
};

int main(){
    vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1},{1,1,1}};
    cout<<(new Solution)->minPathSum(grid);
}
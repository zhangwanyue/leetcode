//
// Created by vera on 19-3-30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int getDigitSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }

    int movingCountCore(int threadhold, int rows, int cols, int row, int col, bool* visited){
        int count = 0;
        if(0<=row && row<rows && 0<=col && col<cols && !visited[row*cols + col] && getDigitSum(row)+getDigitSum(col)<= threadhold){
            visited[row*cols + col]=true;
            count = 1 +
                    movingCountCore(threadhold, rows, cols, row+1, col, visited) +
                    movingCountCore(threadhold, rows, cols, row, col+1, visited) +
                    movingCountCore(threadhold, rows, cols, row-1, col, visited) +
                    movingCountCore(threadhold, rows, cols, row, col-1, visited);
        }
        return count;
    }

public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited = new bool[rows*cols];
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                visited[i*cols + j]=false;
            }
        }
        return movingCountCore(threshold, rows, cols, 0, 0, visited);
    }
};

int main(){
    int threshold, rows, cols;
    cin>>threshold>>rows>>cols;

    cout<<(new Solution)->movingCount(threshold, rows, cols);
}
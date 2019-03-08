//
// Created by vera on 19-2-22.
//
# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> >& matrix, int number){
        bool found = false;
        unsigned long row = matrix.size();
        unsigned long column = matrix.size();
        int row_end = row -1, column_start = 0;
        while(row_end >= 0 && column_start < column){
            if(matrix[row_end][column_start] == number){
                return true;
            }
            if(matrix[row_end][column_start] < number){
                column_start++;
            }
            if(matrix[row_end][column_start] > number){
                row_end--;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int> > matrix = {{1, 2, 8, 9}, {2, 3, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout<< (new Solution)->Find(matrix, 9)<<endl;
}

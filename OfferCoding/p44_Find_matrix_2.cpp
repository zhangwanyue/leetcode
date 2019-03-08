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
        return FindNumber(matrix, row_end, column_start, column, number);
    }

    bool FindNumber(vector<vector<int> >& matrix, int row_end, int column_start, int column, int number){
        if(row_end < 0 || column_start >= column)
            return false;
        if(matrix[row_end][column_start] == number){
            return true;
        }
        if(matrix[row_end][column_start] < number){
            FindNumber(matrix, row_end, column_start+1, column, number);
        }
        if(matrix[row_end][column_start] > number){
            FindNumber(matrix, row_end-1, column_start, column, number);
        }
    }
};

int main(){
    vector<vector<int> > matrix = {{1, 2, 8, 9}, {2, 3, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout<< (new Solution)->Find(matrix, 8)<<endl;
}

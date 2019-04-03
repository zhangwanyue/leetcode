//
// Created by vera on 18-8-5.
//

# include<iostream>
# include<vector>
#include <algorithm>

using namespace std;
/**
 * 24点
 */

void backtrace(int target, vector<double> vec, int i, string path, double current){
    if(i==vec.size()){
        if(current==target){
            cout<<path<<endl;
        }
        return;
    }
    //加
    backtrace(target, vec, i+1, path + "+", current+vec[i]);
    //减
    backtrace(target, vec, i+1, path + "-", current-vec[i]);
    //乘
    backtrace(target, vec, i+1, path + "*", current*vec[i]);
    //除
    backtrace(target, vec, i+1, path + "/", current/vec[i]);

}

int main(){
    vector<double> vec = {5, 5, 5, 5, 5};
    int target = 24;
    string path = "";
    backtrace(target, vec, 0, path, 0);
}

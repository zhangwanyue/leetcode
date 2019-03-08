//
// Created by vera on 19-3-8.
//

#include<iostream>
#include<vector>
using namespace std;

int main(){
    //静态初始化
    vector<int> vec = {0,1,2,3};
    vector<vector<int> > matrix = {{0,0,0},{1,1}};
    //下标访问
    cout<<matrix[1][1]<<" "<<vec[0]<<endl;
    //迭代器访问
    for(vector<int>::iterator iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    for(auto iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    for(auto& iter: vec){
        cout<< iter <<" ";
    }
    for(vector<vector<int>>::iterator iter1 = matrix.begin(); iter1 != matrix.end(); iter1++){
        for(vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout<< *iter2 <<" ";
        }
    }

}
//
// Created by vera on 19-3-8.
//

#include<iostream>
#include<vector>
using namespace std;

int main(){
    //静态初始化
    vector<int> vec = {0,1,2,3};
    vector<vector<int> > matrix = {{0,1,2},{3,4}};
    //下标访问
    cout<<matrix[1][1]<<" "<<vec[0]<<endl;
    //迭代器访问（end()指向的是最后一个元素的下一个位置）
    for(vector<int>::iterator iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto& iter: vec){
        cout<< iter <<" ";
    }
    cout<<endl;
    //双层数组迭代器访问
    for(vector<vector<int>>::iterator iter1 = matrix.begin(); iter1 != matrix.end(); iter1++){
        for(vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout<< *iter2 <<" ";
        }
    }
    cout<<endl;
    for(auto iter1 = matrix.begin(); iter1 != matrix.end(); iter1++){
        for(auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout<< *iter2 <<" ";
        }
    }
    cout<<endl;
    for(auto& iter1 : matrix){
        for(auto& iter2 : iter1){
            cout<< iter2 <<" ";
        }
    }
    cout<<endl;
    //逆向迭代器
    for(auto iter = vec.rbegin(); iter != vec.rend(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    //容量
    cout<<"size:"<<vec.size()<<" isEmpty:"<<vec.empty()<<" max_size:"<<vec.max_size()<<" capacity:"<<vec.capacity()<<endl;
    vec.reserve(100);
    cout<<"size:"<<vec.size()<<" isEmpty:"<<vec.empty()<<" max_size:"<<vec.max_size()<<" capacity:"<<vec.capacity()<<endl;
    vec.shrink_to_fit();
    cout<<"size:"<<vec.size()<<" isEmpty:"<<vec.empty()<<" max_size:"<<vec.max_size()<<" capacity:"<<vec.capacity()<<endl;
}
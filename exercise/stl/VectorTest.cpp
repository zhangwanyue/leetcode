//
// Created by vera on 19-3-8.
//

#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int>& vec){
    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    //静态初始化
    vector<string> words(5, "hello");
    vector<int> vec = {0,1,2,3,4};
    vector<vector<int> > matrix = {{0,1,2},{3,4}};
    //初始化固定大小
    vector<int> vecTemp(10);
    //元素访问
    cout<<matrix[1][1]<<" "<<vec[0]<<endl;
    cout<<matrix.at(1).at(1)<<" "<<vec.at(0)<<endl;
    cout<<vec.back()<<vec.front()<<endl;//获取最后一个元素和第一个元素
    //迭代器访问（end()指向的是最后一个元素的下一个位置）
    for(vector<int>::iterator iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto iter = vec.begin(); iter!=vec.end(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto iter : vec){
        cout<< iter <<" ";
    }
    cout<<endl;
    //双层vector迭代器访问
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
    for(auto item1 : matrix){
        for(auto item2 : item1){
            cout<< item2 <<" ";
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
    //插入元素
    printVec(vec);
    vec.insert(vec.begin()+2, 10); //插入单个元素
    printVec(vec);
    int arr[] = {101, 102, 103};
    vec.insert(vec.begin()+3, arr, arr+3); //插入多个元素（最后一个参数是指向要添加的最后一个元素的下一个元素的迭代器）
    printVec(vec);
    vector<int> vec2 = {104, 105, 106};
    vec.insert(vec.begin()+6, vec2.begin(), vec2.end());
    printVec(vec);
    //push & pop
    vec.push_back(1000);
    printVec(vec);
    vec.pop_back();
    printVec(vec);
    //清除全部元素
    vec.clear();
    printVec(vec);
    //比较
    vector<int> vector1 = {0,1,2,3};
    vector<int> vector2 = {0,1,2,3};
    vector<int> vector3 = {0,1,3};
    cout<< (vector1==vector2) << " " << (vector1>vector3) << endl;

    //二维数组初始化大小
    vector<vector<int>> vector4(5);
    for(int i=0; i<5; i++){
        vector4[i].reserve(10);
    }
    vector4[3][3]=10;
    cout<<vector4[3][3]<<endl;

    vector<vector<int> >vector5(10,vector<int>(5));//新建一个vector<int>，然后拷贝10个该元素给vector5
    vector5[7][4]=10;
    cout<<vector5[7][4]<<endl;

    int temp[10];
    temp[9]=10;
    cout<<temp[9]<<endl;
    cout<<*(temp+9)<<endl;

    int* temp2 = new int[10];
    temp2[9]=10;
    cout<<temp2[9]<<endl;
    cout<<*(temp2+9)<<endl;

    vector<int> vector6 = {0,1,2,3,4,5,6,7,8,9};
//    vector6.reserve(10);
//    for(int i=0; i<10; i++){
//        cin>>vector6[i];
//    }
//    for(int i=0; i<10; i++){
//        cout<<vector6[i]<<" ";
//    }

    //迭代的时候删除元素
    for(int i=0; i<vector6.size();){
        cout<<vector6[i]<<" ";
        vector6.erase(vector6.begin());
    }
}


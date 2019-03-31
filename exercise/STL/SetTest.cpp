//
// Created by vera on 19-3-28.
//
#include<iostream>
#include<set>
using namespace std;

void printSet(set<int>& vec){
    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

struct Info{
    string name;
    float score;
    bool operator < (const Info &a) const{
        return score<a.score;
    }
};

struct myComp{
    bool operator()(const Info &a, const Info &b){
        return a.score-b.score<0;
    }
};

void printInfoSet(set<Info>& infoSet){
    for(Info info : infoSet){
        cout<<"name: "<<info.name<<" score: "<<info.score<<endl;
    }
}

void printInfoSet(set<Info, myComp>& infoSet){
    for(Info info : infoSet){
        cout<<"name: "<<info.name<<" score: "<<info.score<<endl;
    }
}

//set中每个元素的值都是唯一的，而且系统能够根据元素的值自动进行排序
int main(){
    //静态初始化
    set<int> myset1 = {1, 2, 2, 22};
    set<set<int> > myset2 = {{1, 1}, {2, 1}};
    //迭代器
    for(auto item : myset1){
        cout<<item<<" ";
    }
    cout<<endl;
    for(auto item1 : myset2){
        for(auto item2 : item1){
            cout<<item2<<" ";
        }
    }
    cout<<endl;
    for(set<set<int>>::iterator iterator1 = myset2.begin(); iterator1!=myset2.end(); iterator1++){
        for(set<int>::iterator iterator2 = (*iterator1).begin(); iterator2!=(*iterator1).end(); iterator2++){
            cout<< *iterator2 << " ";
        }
    }
    cout<<endl;
    //容量
    cout<<"isEmpty: "<<myset1.empty()<<"size: "<<myset1.size()<<endl;
    //插入元素
    myset1.insert(3);
    printSet(myset1);
    //擦除元素
    myset1.erase(1);
    printSet(myset1);
    //元素查找
    set<int>::iterator iterator3 = myset1.find(2);
    if(iterator3!=myset1.end()){
        cout<<"has find"<<endl;
    }else{
        cout<<"not find"<<endl;
    }
    cout<<"how many 2: "<<myset1.count(2)<<endl; //因为元素不允许重复，所以结果只可能为０或１
    //清除全部元素
    myset1.clear();
    printSet(myset1);


    //自定义比较函数
    Info info1 = {"alice", 100};
    Info info2 = {"bob", 90};

    set<Info> infoSet = {info1, info2};
    printInfoSet(infoSet);

    set<Info, myComp> infoSet2 = {info1, info2};
    printInfoSet(infoSet2);
}

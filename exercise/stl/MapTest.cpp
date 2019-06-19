//
// Created by vera on 19-3-28.
//
#include <iostream>
#include <map>
using namespace std;

void printMap(map<string, int> map1){
    for(auto item:map1){
        cout<<"name: "<<item.first<<" score: "<<item.second<<" ";
    }
    cout<<endl;
}

//map是有序键值对容器，它的元素的键是唯一的，可以用比较函数（Compare）排序键，map通常实现为红黑树
int main(){
    //静态初始化
    map<string, int> map1 = {{"alice", 10},{"bob", 20}};
    map1["joey"] = 30;
    //元素访问
    cout<<map1["alice"]<<endl;
    //迭代器访问
    for(map<string, int>::iterator iterator1 = map1.begin(); iterator1!=map1.end(); iterator1++){
        cout<<"name: "<<iterator1->first<<" score: "<<iterator1->second<<" ";
    }
    cout<<endl;
    //容量
    cout<<"size: "<<map1.size()<<" isEmpty: "<<map1.empty()<<endl;
    //插入元素
    map1.insert({"jude", 40});
    printMap(map1);
    //查找元素
    map<string, int>::iterator iterator2 = map1.find("jude");//寻找带有特定键的元素
    if(iterator2!=map1.end()){
        cout<<"has find"<<endl;
    }else{
        cout<<"not find"<<endl;
    }
    cout<<map1.count("jude")<<endl;//返回匹配特定键的元素数量
    //删除元素
    map<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"},
                                    {4, "four"}, {5, "five"}, {6, "six"}};
    for(auto it = c.begin(); it != c.end(); )
        if(it->first % 2 == 1)
            it = c.erase(it);//删除迭代器指向的元素（注意迭代器是如何更新的）
        else
            ++it;
    for(auto& p : c)
        cout << p.second << ' ';
    cout<<endl;
    c.erase(2);//删除key为２的元素
    for(auto& p : c)
        cout << p.second << ' ';
}

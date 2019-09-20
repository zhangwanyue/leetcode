//
// Created by vera on 19-9-20.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

struct cmp{
    bool operator()(int a, int b){
        return a>b;
    }
};

int main() {
    std::priority_queue<int> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    print_queue(q2);

//    // 用 lambda 比较元素。
//    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
//    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    std::priority_queue<int, std::vector<int>, cmp> q3;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    print_queue(q3);

}
//
// Created by vera on 19-4-3.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top()); //把stack1中的全部弹入stack2中
                stack1.pop();
            }
        }
        int item = stack2.top();
        stack2.pop();
        return item;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution solution = Solution();
    solution.push(0);
    solution.push(1);
    cout<<solution.pop()<<endl;
    solution.push(2);
    cout<<solution.pop()<<endl;
    solution.push(3);
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
}
//
// Created by vera on 18-7-17.
//

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

/**
 * 用队列做的
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<int> mydeque;
        int max = 0;
        int temp = 0;
        for(char c:s){
            deque<int>::iterator findIter = find(mydeque.begin(),mydeque.end(), c);
            if(findIter == mydeque.end() || mydeque.empty()){//在队列中没有找到相同元素
                mydeque.push_back(c);
                temp ++;
                if(temp > max){
                    max = temp;
                }
            }else{//找到了
                deque<int>::iterator dequeIter = mydeque.begin();
                while(dequeIter != findIter+1){//将查找到的重复元素及该元素之前的元素全部出队
                    mydeque.pop_front();
                    temp --;
                    dequeIter ++;
                }
                //将当前的元素入队
                mydeque.push_back(c);
                temp ++;
            }
        }
        return max;
    }
};

//int main(){
//    string s = "abcabcbb";
//    cout<< (new Solution)->lengthOfLongestSubstring(s);
//}

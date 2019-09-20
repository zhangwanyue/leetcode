//
// Created by vera on 19-9-15.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> myDeque(n);
    for(int i=0; i<n; i++){
        cin>>myDeque[i];
    }

    int result=0;
    int isMyTurn=1;
    while(!myDeque.empty()){
        if(isMyTurn%2){
            if(myDeque.front()>myDeque.back()){
                result+=myDeque.front();
                myDeque.pop_front();
            }else{
                result+=myDeque.back();
                myDeque.pop_back();
            }
        }else{
            if(myDeque.front()>myDeque.back()){
                myDeque.pop_front();
            }else{
                myDeque.pop_back();
            }
        }
    }
    cout<<result;
    return 0;
}
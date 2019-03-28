//
// Created by vera on 19-3-10.
//

#include <iostream>
#include <deque>

using namespace std;
int main(){
    int n;
    cin>>n;
    deque<int> porker(n);
    for(int i=0; i<n; i++){
        cin>>porker[i];
    }

    int temp;
    for(;n>1;n--){
        porker.pop_front();
        temp = porker.front();
        porker.pop_front();
        porker.push_back(temp);
    }
    cout<<porker.front();
}

//样例输入：
//n=8;
//deque<int> porker = {1, 3, 5, 7, 4, 2, 6, 8};
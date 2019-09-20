//
// Created by vera on 19-8-9.
//
#include <iostream>
#include <vector>
using namespace std;

int myCount(vector<char> vec, int end){
    int max=0;
    int temp=0;
    for(int i=end; i>=0; i--){
        if(vec[i]=='T'){
            temp += 1;
        }else{
            temp -= 1;
        }
        if(temp==0){
            int tempMax = end-i+1;
            if(tempMax>max){
                max = tempMax;
            }
        }
    }
    return max;
}

int main(){
    vector<char> vec;
    char c;
    while(cin>>c){
        vec.push_back(c);
    }
//    vector<char> vec = {'Y', 'T', 'Y', 'T'};
    vector<int> count(vec.size());
    count[0]=0;
    for(int i=1; i<vec.size(); i++){
        count[i]=myCount(vec, i);
    }
    int max=0;
    for(int i=0; i<count.size(); i++){
        if(count[i]>max){
            max = count[i];
        }
    }
    cout<<max;
}

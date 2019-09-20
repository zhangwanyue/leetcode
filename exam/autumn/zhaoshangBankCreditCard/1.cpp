//
// Created by vera on 19-9-15.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<char> vec;
    char c;
    while(cin>>c){
        vec.push_back(c);
    }

//    vector<char> vec = {'R', 'R', 'L', 'R', 'L'};

    vector<int> result;
    for(int i=0; i<vec.size(); i++){
        result.push_back(0);
    }

    for(int i=0; i<vec.size(); i++){
        if(vec[i]=='L'){
            for(int j=i-1; j>=0; j--){
                if(vec[j]=='R'){
                    if((i-j)%2==0){
                        result[j]++;
                    }else{
                        result[j+1]++;
                    }
                    break;
                }
            }
        }else if(vec[i]=='R'){
            for(int j=i+1; j<vec.size(); j++){
                if(vec[j]=='L'){
                    if((i-j)%2==0){
                        result[j]++;
                    }else{
                        result[j-1]++;
                    }
                    break;
                }
            }
        }
    }

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;

}
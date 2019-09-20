//
// Created by vera on 19-8-9.
//

#include <iostream>
#include <vector>
using namespace std;


int myCount(int x1, int x2){
    int result = 0;
    for(int i=x1+1; i<=x2; i++){
        if(i%10!=4 && i%10!=-4){
            result++;
        }
    }
    return result;
}

int main(){
    int x, y;
    cin>>x>>y;
    if(x%10==4 || y%10==4 || x==0 || y==0){
        cout<<"illegal input";
        return 0;
    }
    int result = 0;
    if(x>y){
        int temp = x;
        x = y;
        y = temp;
    }
    if(y-x>10){
        result += myCount(x, y-((y-x)/10)*10);
        result += (y-x)/10*9;
    }else{
        result += myCount(x, y);
    }
    if(x<0 && y>0){
        result-=1;
    }
    cout<<result;
}


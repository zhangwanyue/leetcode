//
// Created by vera on 19-3-30.
//

#include<iostream>
using namespace std;
int main(){
    int num;
    int sum;
    cin>>num;
    while(num>0){
        sum += num%2;
        num = num/2;
    }
    cout<<sum;
}
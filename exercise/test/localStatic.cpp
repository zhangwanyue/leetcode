//
// Created by vera on 19-4-5.
//
#include <iostream>
using namespace std;

int addStatic(){
    int static a = 0;
    a--;
    cout<<a<<endl;
}

int main(){
    addStatic();
    addStatic();
}
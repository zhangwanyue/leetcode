//
// Created by vera on 19-4-15.
//
#include <iostream>
using namespace std;

void changeNumUsingRef(int& num){
    num = 0;
}

void changeNumUsingPointer(int* num){
    *num = 0;
}

int main(){
    int num1 = 10;
    changeNumUsingRef(num1);
    cout<<num1<<endl;

    int num2 = 10;
    changeNumUsingPointer(&num2);
    cout<<num2<<endl;
}
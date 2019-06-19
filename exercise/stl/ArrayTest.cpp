//
// Created by vera on 19-6-19.
//

#include<iostream>
using namespace std;

void func1(int a[5]){
    a[0] = 10;
}

void func2(int b[5][5]){
    b[0][0] = 10;
}

int main(){
    int a[5] = {0, 1, 2, 3};
    func1(a); // a中存的是一维数组第一个元素的地址，参数传递的时候只把该地址拷贝过去了（不会拷贝整个数组）
    cout<<a[0]<<endl;

    int b[5][5] = {{0, 1, 2, 3}};
    func2(b); // b中存的是二维数组第一个元素的地址（b和b[0]的值是一样的），参数传递的时候只把该地址拷贝过去了（不会拷贝整个数组）
    cout<<b[0][0]<<endl;

    // 数组初始化
    // ref: https://stackoverflow.com/questions/1920430/c-array-initialization
    // In C language = { 0 } is an idiomatic universal zero-initializer. This is also almost the case in C++.
    // Since this initalizer is universal, for bool array you don't really need a different "syntax". 0 works as an initializer for bool type as well, so
    bool myBoolArray[10] = {0};
    // is guaranteed to initialize the entire array with false. As well as
    char* myPtrArray[10] = {0};
    // If you believe it improves readability, you can certainly use
    bool myBoolArray2[10] = { false };
    char* myPtrArray2[10] = { nullptr };
    // but the point is that = { 0 } variant gives you exactly the same result.
    // However, in C++ = { 0 } might not work for all types, like enum types.
    // i.e. just an empty pair of {}. This will default-initialize an array of any type (assuming the elements allow default initialization), which means that for basic (scalar) types the entire array will be properly zero-initialized
    bool myBoolArray3[10] = {};
}
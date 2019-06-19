//
// Created by vera on 19-3-30.
//
#include <iostream>
using namespace std;


//不能将局部变量作为引用或者指针返回（因为局部变量在方法结束后就销毁了）
int & squareRef(int num){
    int localResult = num * num;
    return localResult;
}

int * squarePtr(int num){
    int localResult = num * num;
    return &localResult;
}


//在堆上分配空间，作为引用或者指针返回，是可以的
int * squareDynamicAllocatedPtr(int num){
    int * dynamicAllocatedResult = new int(num * num);
    return dynamicAllocatedResult;
}

int & squareDynamicAllocateRef(int num){
    int * dynamicAllocatedResult = new int(num * num);
    return *dynamicAllocatedResult;
}

int main(){
    /*
    //没有初始化，ptr指向一个invalid memory location，然后又要修改该内存区域的值，当然会发生冲突
    int * ptr;
    *ptr = 55;
    cout<<(*ptr)<<endl;
     */

    /*
    cout<<squareRef(10)<<endl;
    cout<<(*squarePtr(10))<<endl;
     */

    cout<<(*squareDynamicAllocatedPtr(10))<<endl;
    cout<<squareDynamicAllocateRef(10)<<endl;


    //指针是常量，和指向常量数据的指针
    int i1=8, i2=9;
    const int * ptr1 = &i1;//指针是非常量，指向常量数据
    ptr1 = &i2;//指针本身可变
//    *ptr1 = 10;//指针指向内容不可变

    int * const ptr2 = &i1;//指针是常量，指向非常量数据
//    ptr2 = &i2;//指针本身不可变
    *ptr2 = 10;//指针指向内容可变
}


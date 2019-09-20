//
// Created by vera on 19-9-19.
//
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


//循环读入多行(EOF结尾，键盘输入ctrl+D)，每行有n个字符串，字符串用空格分割。每行的字符串都存入vector<string>中
int main(){
    string str;
    while(getline(cin, str)){
        vector<string> vec;
        stringstream input(str);
        string splitStr;
//        while(input>>splitStr){
//            vec.push_back(splitStr);
//        }
        //getline默认是使用'\n'做分割，但是第三个参数可以指定自定义的分隔符（比如这里用逗号做分割）
        while(getline(input, splitStr, ',')){
            vec.push_back(splitStr);
        }
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<endl;
        }
    }
}


/*
//读入用特殊符号分割的字符串，子字符串都存入vector<string>中
int main(){
    string str;
    vector<string> splitStr;
    //getline默认是使用'\n'做分割，但是第三个参数可以指定自定义的分隔符（比如这里用逗号做分割）
    while(getline(cin,str,',')){
        splitStr.push_back(str);
    }
    for(int i=0; i<splitStr.size(); i++){
        cout<<splitStr[i]<<endl;
    }
    cout<<"end";
}
*/

//用string分割string见StringTest.cpp
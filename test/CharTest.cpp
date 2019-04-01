//
// Created by vera on 19-4-1.
//

#include <iostream>
#include <cstring>

using namespace std;

class Test{
    char* name;
public:
    Test(char* c):name(c){
        c[0]='a';
    }
};


int main(){
//    char* c = new char[100];
//    strcpy(c, "hello"); //会将hello结尾的'\0'也拷贝进来
    char* c = "hello";
    c[0]='a';
//    Test* test = new Test(c);
    for(int i=0; c[i]!='\0'; i++){
        cout<<c[i];
    }
}
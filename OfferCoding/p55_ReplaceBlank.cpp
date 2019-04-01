//
// Created by vera on 19-4-1.
//
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr || length<=0)
            return;
        int originalLength = 0;
        int numberOfBlank = 0;
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]==' '){
                numberOfBlank++;
            }
            originalLength++;
        }
        int newLength = originalLength + 2*numberOfBlank;
        if(length<newLength)
            return;

        for(int indexOfOrigin=originalLength, indexOfNew=newLength; indexOfOrigin>=0; indexOfOrigin--){
            if(str[indexOfOrigin]==' '){
                str[indexOfNew--]='0';
                str[indexOfNew--]='2';
                str[indexOfNew--]='%';
            }else{
                str[indexOfNew--]=str[indexOfOrigin];
            }
        }
    }
};

int main(){
    char* str = new char[100];
    strcpy(str, "We are happy");
    (new Solution)->replaceSpace(str, 100);
    for(int i=0; str[i]!='\0'; i++){
        cout<<str[i];
    }
    cout<<endl;
}

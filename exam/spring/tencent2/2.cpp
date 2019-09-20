//
// Created by vera on 19-4-5.
//

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=0; i<(int)a.size()-1;){
            if(a[i]!=a[i+1]){
                a.erase(i, 2);
                flag = true;
            }else{
                i++;
            }
        }
    }
    cout<<a.size();
}

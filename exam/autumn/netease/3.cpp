//
// Created by vera on 19-8-3.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int n;
int array[MAXN];
bool odd = false, even = false;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>array[i];
        if(array[i]%2==0){
            even = true;
        }else{
            odd = true;
        }
    }
    if(odd^even){
        for(int i=1; i<=n; i++){
            cout<<array[i]<<" ";
        }
    }else{
        sort(array+1, array+n+1);
        for(int i=1; i<=n; i++){
            cout<<array[i]<<" ";
        }
    }
}

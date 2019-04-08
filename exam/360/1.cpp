//
// Created by vera on 19-4-3.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int sum=0;
        sum += d;
        if(a>c){ //将3人队伍组成4人
            a -= c;
            sum += c;
        }else{
            sum += a;
            a = 0;
        }
        sum += (a+2*b)/4;
        cout<<sum<<endl;
    }
}
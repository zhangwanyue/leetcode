//
// Created by vera on 19-3-30.
//

#include<iostream>
using namespace std;


//答案不对啊……
int getDigitSum(int num){
    int sum = 0;
    while(num>0){
        sum += num%10;
        num = num/10;
    }
    return sum;
}

int main(){
    int m, n, k;
    cin>>m>>n>>k;
    int sum=0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(getDigitSum(i)+getDigitSum(j)<k)
                sum++;
        }
    }

    cout<<sum;
    return 0;
}
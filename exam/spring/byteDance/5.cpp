//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        vector<int> a;
        a.reserve(num);
        for(int j=0; j<num; j++){
            cin>>a[j];
        }


        sort(a.begin(), a.end());
        int times;
//        if(num%3 == 2 || num%3 == 0){
            if(num%3 == 0){
                times = num/3;
            }else{
                times = num/3 + 1;
            }

            int min = 0;
            for(int j=num-1; j>=0; ){
                if(j == 3){
                    min += a[j] + a[j-2];
                    j = j-4;
                }
                min += a[j];
                j -= 3;
            }
            cout<<min;
//        }

//        if(num%3 == 1){
//
//        }

    }

}
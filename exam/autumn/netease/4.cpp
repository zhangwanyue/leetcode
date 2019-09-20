//
// Created by vera on 19-8-3.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> num(n);
    int count, x;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    for(int i=0; i<q; i++){
        count=0;
        cin>>x;
        for(int j=0; j<n; j++){
            if(num[j]>=x){
                num[j]--;
                count++;
            }
        }
        cout<<count<<endl;
    }
}
//
// Created by vera on 19-9-19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int main(){
//    int n, m;
//    cin>>n>>m;
//    vector<int> bucket(2001);
//    for(int i=0; i<bucket.size(); i++){
//        bucket[i] = 0;
//    }
//    int temp;
//    for(int i=0; i<n; i++){
//        cin>>temp;
//        bucket[temp+1000]++;
//    }
//    int min;
//    int tempMin = 0;
//    for(int i=0; i<m; i++){
//        tempMin += (i-1000)*bucket[i];
//    }
//    min = tempMin;
//    for(int j=m; j<bucket.size(); j++){
//        tempMin = tempMin + (j-1000)*bucket[j] - (j-1000-m)*bucket[j-m];
//        if(tempMin<min){
//            min = tempMin;
//        }
//    }
//    cout<<min;
//}

//int main(){
//    int n, m;
//    cin>>n>>m;
//    vector<int> bucket(11);
//    for(int i=0; i<bucket.size(); i++){
//        bucket[i] = 0;
//    }
//    int temp;
//    for(int i=0; i<n; i++){
//        cin>>temp;
//        bucket[temp+5]++;
//    }
//    int min;
//    int tempMin = 0;
//    int firstNotZero = 0;
//    for(int i=0; i<bucket.size(); i++){
//        if(bucket[i]!=0){
//            break;
//        }
//        firstNotZero++;
//    }
//    for(int i=firstNotZero; i<m+firstNotZero; i++){
//        tempMin += (i-5)*bucket[i];
//    }
//    min = tempMin;
//    for(int j=m; j<bucket.size(); j++){
//        tempMin = tempMin + (j-5)*bucket[j] - (j-5-m)*bucket[j-m];
//        if(tempMin<min){
//            min = tempMin;
//        }
//    }
//    cout<<min;
//}
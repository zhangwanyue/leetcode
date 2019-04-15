//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    char a[20];
    vector<vector<char>> vec;
    while(cin.getline(a,20,EOF)){
        vector<char> tmpVec;
        for(int i=0;i<20;i++){
            if(a[i]=='0'||a[i]=='1'||a[i]=='2'){
                tmpVec.push_back(a[i]);
                cout<<a[i];
            }
        }
        a[20] = {NULL};
        vec.push_back(tmpVec);
        for(int j=0; j<tmpVec.size(); j++){
            cout<<tmpVec[j]<<" ";
        }
        cout<<endl;
    }
//    int size = vec.size();
//    for(int i=0; i<size; i++){
//        for(int j=0; j<size; j++){
//            cout<<vec[i][j]<<" ";
//        }
//        cout<<endl;
//    }

}
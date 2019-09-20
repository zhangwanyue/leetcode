//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int checkVec(vector<vector<int>>& vec, int num1, int num2){
    int maxLen = 0;
    int tmpMax = 0;
    bool flag;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j+=2){
            flag = false;
            if(vec[i][j] == num1 && vec[i][j+1] == num2){
                flag = true;
                tmpMax ++;
                if(maxLen<tmpMax){
                    maxLen = tmpMax;
                }
                vec[i].erase(vec[i].begin()+j);
                vec[i].erase(vec[i].begin()+j+1);

            }
        }
        if(!flag){
            tmpMax = 0;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector<vector<int>> vec;
        int m;
        cin>>m;
        for(int j=0; j<m; j++){
            int num;
            cin>>num;
            vector<int> tmpVec;
            for(int k=0; k<num; k++){
                int tmp;
                cin>>tmp;
                tmpVec.push_back(tmp);
            }
            vec.push_back(tmpVec);
        }

        int maxLen = 0;
        for(int j=0; j<m; j++){
            for(int k=0; k<vec[j].size(); k+=2){
                int tmpLen = checkVec(vec, vec[j][k], vec[j][k+1]);
                if(tmpLen>maxLen){
                    maxLen = tmpLen;
                }
            }
        }
        cout<<maxLen;

    }
}
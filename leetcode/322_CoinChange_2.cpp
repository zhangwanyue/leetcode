//
// Created by vera on 19-4-7.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& vec){
        if(vec.empty()){
            return -1;
        }
        int min = vec[0];
        for(int i=1; i<vec.size(); i++){
            if(vec[i]<min){
                min = vec[i];
            }
        }
        return min;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        map<int, int> coinsDp;
        coinsDp[0] = 0;
        for(int i=0; i<coins.size(); i++){
            if(coins[i]<amount+1)
                coinsDp[coins[i]] = 1;
        }
        for(int i=1; i<amount+1; i++){
            vector<int> tmp;
            for(int j=0; j<coins.size() && i-coins[j] >= 0; j++){
                if(coinsDp.find(i-coins[j])!=coinsDp.end() && coinsDp[i-coins[j]]!= -1){
                    tmp.push_back(coinsDp[i-coins[j]]);
                }
            }
            int tmpMin = findMin(tmp);
            if(tmpMin!=-1){
                coinsDp[i] = tmpMin+1;
            } else{
                coinsDp[i] = -1;
            }
        }
        return coinsDp[amount];
    }
};

int main(){
    int amount = 6249;
    vector<int> coins = {186,419,83,408} ;
    cout<<(new Solution)->coinChange(coins, amount);
}

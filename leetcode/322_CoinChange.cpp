//
// Created by vera on 19-4-7.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinsDp(amount+1, amount+1);
        coinsDp[0] = 0;
        for(int i=0; i<coins.size(); i++){
            if(coins[i]<amount+1)
                coinsDp[coins[i]] = 1;
        }
        for(int i=1; i<amount+1; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0)
                    coinsDp[i] = min(coinsDp[i], coinsDp[i-coins[j]]+1);
            }
        }
        return coinsDp[amount]>amount ? -1 : coinsDp[amount];
    }
};

int main(){
    int amount = 3;
    vector<int> coins = {4} ;
    cout<<(new Solution)->coinChange(coins, amount);
}
















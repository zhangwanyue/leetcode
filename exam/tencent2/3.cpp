//
// Created by vera on 19-4-5.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int findMax(vector<int> vec) {
//    int max = -1;
//    for (auto v : vec) {
//        if (max < v) max = v;
//    }
//    return max;
//}

int minMoney(int i, int nowPower, int nowMoney, vector<int>& power, vector<int>& money, bool flag){
    if(i>=power.size()){
        return nowMoney;
    }
    if(nowPower<power[i]){ //必须要
        nowPower = nowPower + power[i];
        nowMoney = money[i] + min(minMoney(i+1, nowPower, nowMoney, power, money, true), minMoney(i+1, nowPower, nowMoney, power, money, false));
    }else if(flag){//要
        nowPower = nowPower + power[i];
        nowMoney = money[i] + min(minMoney(i+1, nowPower, nowMoney, power, money, true), minMoney(i+1, nowPower, nowMoney, power, money, false));
    }else{ //不要
        nowMoney = min(minMoney(i+1, nowPower, nowMoney, power, money, true), minMoney(i+1, nowPower, nowMoney, power, money, false));
    }
    return nowMoney;
}

int main() {
    int n;
    vector<int> power, money;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        power.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        money.push_back(tmp);
    }
//    int maxPower = findMax(power);
//    int sumMoney = 0;
//    int sumPower = 0;
//    int nowPower = 0;


    cout<<minMoney(0, 0, 0, power, money, true);

//    for(int i=0; i<n; i++){
//        if(nowPower<power[i]){ //必须要
//            sumMoney += money[i];
//            sumPower += power[i];
//        }else{
//
//        }
//    }
//

}

//3
//8 5 10
//1 1 2
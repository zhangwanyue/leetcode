//
// Created by vera on 19-3-10.
//
#include <iostream>
#include <vector>
using namespace std;

int nextStep(vector<int> floors, int n, int step, bool flag){
    //第一步
    if(step == 0)
        return 0;
    if(flag){//下一步使用了跳技能
        return nextStep(floors, n, step-1, false) + floors[step];
    }else{
        int sum1 = nextStep(floors, n, step-1, true); //这一步使用跳技能，跳一步
        int sum2 = nextStep(floors, n, step-1, false) + floors[step]; //这一步不使用跳技能
        int min = sum1 < sum2 ? sum1 : sum2;
        if(step>=2){
            int sum3 = nextStep(floors, n, step-2, true); //这一步使用跳技能，跳两步
            min = min < sum3 ? min : sum3;
        }
        return min;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> floors(n);
    for(int i=0; i<n; i++){
        cin>>floors[i];
    }
    cout<< nextStep(floors, n, n-1, false);//最后一步不限制（最后一步的下一步没有使用跳技能）
}
//测试输入：
//5
//3
//5
//1
//8
//4
//输出：
//１



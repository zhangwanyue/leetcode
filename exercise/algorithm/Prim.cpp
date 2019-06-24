//
// Created by vera on 19-6-24.
//
#include <iostream>
using namespace std;

const int INF = INT16_MAX; // INT32_MAX再加数会溢出的
const int V = 5; // 顶点数量
bool used[V];
int mincost[V]; // 从used集合出发的边到各个顶点的最小权值
int cost[V][V] = {{0, 1, 3, INF, INF},
                  {INF, 0, 1, INF, 10},
                  {INF, INF, 0, 2, INF},
                  {INF, INF, INF, 0, 6},
                  {INF, INF, INF, INF, 0}};

int prim(){
    for(int i=0; i<V; i++){
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while(true){
        int v = -1;
        for(int i=0; i<V; i++){
            if(!used[i] && (v == -1 || mincost[i] < mincost[v])){
                v = i;
            }
        }
        if(v == -1){
            break;
        }
        used[v] = true; // 把顶点v加入used
        res += mincost[v];

        for(int i=0; i<V; i++){ // 使用新加入used的点更新mincost
            mincost[i] = min(mincost[i], cost[v][i]);
        }
    }

    return res;
}

int main(){
    int sumCost = prim();
    cout<<sumCost<<endl;
}
//
// Created by vera on 19-6-24.
//
#include <iostream>
using namespace std;

const int INF = INT16_MAX; // INT32_MAX再加数会溢出的

//const int V = 5; // 顶点数量
//// d[u][v]表示从u出发到v的最短距离
//int d[V][V] = {{0, 1, 3, INF, INF},
//                  {INF, 0, 1, INF, 10},
//                  {INF, INF, 0, 2, INF},
//                  {INF, INF, INF, 0, 6},
//                  {INF, INF, INF, INF, 0}};

const int V = 4;
int d[V][V] = {{0, 1, INF, 3},
               {INF, 0, INF, 1},
               {INF, INF, 0, INF},
               {INF, INF, 2, 0}};

void floyd(){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main(){
    floyd();
    cout<<d[0][2]<<endl;
}

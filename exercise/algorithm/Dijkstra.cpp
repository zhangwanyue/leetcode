//
// Created by vera on 19-6-23.
//
#include <iostream>
using namespace std;

const int INF = INT16_MAX; // INT32_MAX再加数会溢出的
const int V = 5; // 顶点数量
int cost[V][V] = {{0, 1, 3, INF, INF},
                  {INF, 0, 1, INF, 10},
                  {INF, INF, 0, 2, INF},
                  {INF, INF, INF, 0, 6},
                  {INF, INF, INF, INF, 0}};
int dist[V]; // 从顶点s出发到各个顶点的最短距离
bool used[V]; // 已经确定了的顶点

/**
 * 求从起点s出发到各个顶点的最短距离
 * @param s 起点
 */
void dijkstra(int s){
    fill(dist, dist+V, INF);
    fill(used, used+V, false);
    dist[s] = 0;
    while(true){
        int v = -1; // 用来标记这次确定的到s最近的顶点
        // 从尚未确定的顶点中选择一个到s距离最近的
        for(int i=0; i<V; i++){
            if(!used[i] && (v==-1 || dist[i]<dist[v])){
                v = i;
            }
        }
        if(v == -1){ // 如果这次没有要新确定的顶点，那就代表全部顶点都确定了，就可以结束了
            break;
        }
        used[v] = true;
        // 使用新确定的顶点，计算经过该顶点，s到各个顶点的距离是否比之前的小
        for(int i=0; i<V; i++){
            dist[i] = min(dist[i], dist[v] + cost[v][i]);
        }
    }
}

int main(){
    dijkstra(0);
    for(int i=0; i<V; i++){
        cout<<dist[i]<<endl;
    }
}
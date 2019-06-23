//
// Created by vera on 19-6-21.
//
#include <iostream>
#include <vector>

using namespace std;

// 题目：使用两种颜色（用1和-1表示这两种颜色），给图的顶点上色，要使相邻的顶点颜色不同，可否实现？题目保证没有重边和自环
// 使用邻接表做
// 0 - 1
//   X
// 2 - 3
struct vertex{ //存储的使vertex顶点的边
    int index;
    vector<int> neighbor;
    vertex(int index, const vector<int> &neighbor) : index(index), neighbor(neighbor) {}
};

const vector<vertex> G = {vertex(0, {1, 3}), vertex(1, {0, 2}), vertex(2, {1, 3}), vertex(3, {0, 2})};

const int V = 4;
int color[V] = {}; // 全部初始化为0


// 将顶点v染成颜色c
bool dfs(int v, int c){
    color[v] = c;
    for(int i=0; i<G[v].neighbor.size(); i++){
        if(color[(G[v].neighbor)[i]]== c){
            return false;
        }
    }
    for(int i=0; i<G[v].neighbor.size(); i++){
        // 如果邻接边还没染色，则给它染色
        if(color[(G[v].neighbor)[i]] == 0){
            if(!dfs((G[v].neighbor)[i], -c)){
                return false;
            }
        }
    }
    return true;
}


int main(){
    for(int i=0; i<V; i++){
        if(color[i] == 0){
            if(!dfs(i, 1)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;

    for(int i=0; i<V; i++){
        cout<<color[i]<<endl;
    }
}

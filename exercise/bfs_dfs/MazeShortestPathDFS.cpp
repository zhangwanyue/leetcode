//
// Created by vera on 19-6-18.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT32_MAX;

// 测试样例1
const int N=10, M=10;
char maze[N][M]= {{'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
                    {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
                    {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
                    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
                    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
                    {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
                    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
                    {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
                    {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'}};
pair<int, int> startPoint(0, 1);
pair<int, int> endPoint(9, 8);


//// 测试样例2
//const int N = 3, M = 3;
//char maze[N][M] = {{'.', 'S', '.'},
//                   {'.', '.', '.'},
//                   {'.', '.', 'G'}};
//pair<int, int> startPoint(0, 1);
//pair<int, int> endPoint(2, 2);


struct Point{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

int pathDistance[N][M];

// 定义一个向四个方向移动的向量
vector<pair<int, int>> direction = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};

// 使用深度优先搜索
void dfs(Point point){
    int x = point.x, y = point.y;

    if(x == endPoint.first && y == endPoint.second){
        return;
    }

    for(int i=0; i<4; i++){
        int nextX = x + direction[i].first;
        int nextY = y + direction[i].second;
        // 判断下一个要搜索的点：
        // 1. 在maze的边界内
        // 2. 可达（即不为#）
        // 3. 之前未被搜索过 或者 当前有更短的路径
        if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M
           && maze[nextX][nextY] != '#'
           && (pathDistance[nextX][nextY] == INF || pathDistance[nextX][nextY] > pathDistance[x][y] + 1) ){
//              && pathDistance[nextX][nextY] == INF){ // 仅仅判断当前被搜索过还不够，还需要判断是否使最短路径
            pathDistance[nextX][nextY] = pathDistance[x][y] + 1;
            dfs(Point(nextX, nextY));// 下一个要搜索的点
        }
    }

    return;
}

int main(){
    // 初始化
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            pathDistance[i][j] = INF;
        }
    }
    pathDistance[startPoint.first][startPoint.second] = 0;

    // 调用dfs
    dfs(Point(startPoint.first, startPoint.second));
    cout<<"shortest path: " << pathDistance[endPoint.first][endPoint.second];
}

// 在求取最短路径时，深度优先搜索需要反复经过同样的状态，所以此时还是使用广度优先搜索比较好
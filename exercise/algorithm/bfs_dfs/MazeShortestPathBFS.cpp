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

queue<Point> pointQueue;

// 使用广度优先搜索
int bfs(){
    while(!pointQueue.empty()){
        int x = pointQueue.front().x;
        int y = pointQueue.front().y;
        pointQueue.pop();
        if(x == endPoint.first && y == endPoint.second){
            return pathDistance[x][y];
        }
        for(int i=0; i<4; i++){
            int nextX = x + direction[i].first;
            int nextY = y + direction[i].second;
            // 判断下一个要搜索的点：
            // 1. 在maze的边界内
            // 2. 可达（即不为#）
            // 3. 之前未被搜索过（不用判断当前是否有更短的路径，因为广度优先搜索中，之前的路径一定比现在的短）
            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M
               && maze[nextX][nextY] != '#'
               && pathDistance[nextX][nextY] == INF){
                pathDistance[nextX][nextY] = pathDistance[x][y] + 1;
                pointQueue.push(Point(nextX, nextY)); // 下一个要搜索的点
            }
        }
    }
    return INF;
}

int main(){
    // 初始化
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            pathDistance[i][j] = INF;
        }
    }
    pathDistance[startPoint.first][startPoint.second] = 0;
    pointQueue.push(Point(startPoint.first, startPoint.second));

    // 调用BFS
    cout<<"shortest path: " << bfs();;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1 , 0, 0, -1};

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    queue<pair<int, int>> que;    //队列
    que.push({x, y});             //起始节点入队
    visited[x][y] = true;         //入队即访问
    while (!que.empty()) {
        pair<int, int> cur = que.front();      //访问队列
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (int i = 0; i < 4; i++) {           //向当前节点的四个方向遍历
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nextx > grid.size() || nexty < 0 || nexty > grid[0].size()) continue;  //出界
            if (!visited[nextx][nexty]) {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }

}

int main() {
    return;
}
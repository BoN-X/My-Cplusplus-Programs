//dijkstra算法注意：
//dijkstra段阿发可以同时求起点到所有节点的最短路径
//权值不能为负数

//三部曲：
//1.选源点到哪个节点近且该节点未被访问过
//2.该最近节点被标记访问过
//3.更新非访问节点到源点的距离
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m ,p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    //存储源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);

    //记录顶点是否被访问过
    vector<bool> visited(n + 1, false);

    minDist[start] = 0;  //起点到自身距离为0

    for (int i = 1; i <= n; i++) {
        int minVal = INT_MAX;
        int cur = 1;

        //第一步
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }

        //第二步
        visited[cur] = true;

        //第三步
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }

    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;
    system("pause");
}
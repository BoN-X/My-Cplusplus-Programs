//Floyd处理多源最短路问题  核心思想：dp
//五部曲
//1.确定dp数组
//grid[i][j][k] = m,节点i到节点j以[1..k]集合中的一个节点为中间节点的最短距离为m
//2.确定递推公式
//1)节点i到节点j的最短路径经过节点k  
//grid[i][j][k] = grid[i][k][k-1] + grid[k][j][k-1]
//2)节点i到节点j的最短路径不经过节点k
//grid[i][j][k] = grid[i][j][k-1]
//递推公式：grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1]， grid[i][j][k - 1])
//3.dp数组初始化
//初始化底层的grid[i][j][0]那个二维层面
//4.遍历顺序
//遍历k在最外层
//5.举例推导dp数组

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2][0] = val;
        grid[p2][p1][0] = val;   //双向图
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <=n ; i++) {
            for (int j = 1; j <=n ;j++) {
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }
    int z, start, end;
    cin >> z;
    while (z--) {
        cin >> start >> end;
        if (grid[start][end][n] == 10005) cout << -1 << endl;
        else cout << grid[start][end][n] << endl;
    }
}

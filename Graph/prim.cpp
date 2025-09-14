//prim三部曲:
//1.选距离生成树最近的节点
//2.最近的节点加入生成树
//3.更新非生成树节点距离生成树的距离（更新minDist数组）

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int v, e;
    int x, y, k;
    cin >> v >> e;
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;
    }
    //所有节点到最小生成树的最小距离
    vector<int> minDist(v + 1, 10001);

    //这个节点是否在树里
    vector<bool> isInTree(v + 1, false);

    //只需要循环n-1次，就可以把n个节点的图连在一起
    for (int i = 1; i < v; i++) {
        //第一步
        int cur = -1;
        int minVal = INT_MAX;
        for (int j = 1; j < v; j++) {
            if (!isInTree[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                cur = j;
            }
        }
        //第二步
        isInTree[cur] = true;

        //第三步
        for (int j = 1; j <= v; j++) {
            if(!isInTree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
            }
        }
    }
    int result = 0;
    for (int i = 2; i <= v; i++) {
        result += minDist[i];
    }
    cout << result <<endl;
    system("pause");
}
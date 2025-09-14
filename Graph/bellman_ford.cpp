//解决带负权值的单源最短路问题
//核心：对所有边进行松弛n-1次操作（n为节点数量）
//松弛：minDist[B] = min(minDist[A] + value, minDist[B])

#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        //p1指向篇p2，权值为val
        grid.push_back({p1, p2, val});
    }
    int start = 1;   //起点
    int end = n;     //终点

    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    for (int i = 1; i < n; i++) {    //松弛n-1次
        for (vector<int> &side : grid) {   //每一次对所有边进行松弛
            int from = side[0];     // 出发
            int to = side[1];       //到达
            int price = side[2];    //权值
            //松弛
            if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) {
                minDist[to] = minDist[from] + price;
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << "unconnected" << endl;
    else cout << minDist[end] << endl;
    system("pause");
}
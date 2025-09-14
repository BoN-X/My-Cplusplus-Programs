//Bellman_ford队列优化算法
//只需要对上一次松弛的时候更新过的节点作为出发节点所连接的边进行松弛
//适合稀疏的图

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;

struct Edge {   //邻接表
    int to;     //链接的节点
    int val;    //边的权值
    Edge(int t, int w): to(t), val(w) {} //构造函数
};

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<list<Edge>> grid(n + 1);
    vector<bool> isInQueue(n + 1);   //加入优化，已经在队里的元素不用重复添加

    //将所有边保存起来
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        //p1指向p2，权值为val
        grid[p1].push_back(Edge(p2, val));
    }
    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;

    queue<int> que;
    que.push(start);

    while (!que.empty()) {
        int node = que.front(); que.pop();
        isInQueue[node] = false;  //从队列里取出的时候要取消标记，保证补充添加
        for (Edge edge : grid[node]) {
            int from = node;
            int to = edge.to;
            int value = edge.val;
            if (minDist[to] > minDist[from] + value) {   //开始松弛
                minDist[to] = minDist[from] + value;
                if (isInQueue[to] == false) {       //已经在队列的元素不用重复添加
                    que.push(to);
                    isInQueue[to] = true;
                }
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << "unconnected" << endl;
    else cout << minDist[end] << endl;
}
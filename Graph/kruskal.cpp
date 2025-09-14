#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//l,r为两边的节点，val为边的数值
struct Edge {
    int l, r, val;
};

//节点数量
int n = 10001;
//并查集关系数组
vector<int> father(n, -1);

void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); //路径压缩
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

int main() {
    int v, e;
    int v1, v2, val;
    vector<Edge> edges;
    int result_val = 0;
    cin >> v >> e;
    while (e--) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    //执行Kruskal算法
    //按边的权值从小到大排序
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.val < b.val;
    });

    init();

    for (Edge edge : edges) {
        int x = find(edge.l);
        int y = find(edge.r);

        if (x != y) {
            result_val += edge.val;
            join(x, y);
        }
    }
    cout << result_val << endl;
    system("pause");
    return 0;
}

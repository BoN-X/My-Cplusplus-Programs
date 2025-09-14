//并查集主要功能
//1.将两个元素添加到一个集合
//2.判断两个元素是否处于一个集合

#include <iostream>
#include <vector>
using namespace std;

int n = 1005;
vector<int> father = vector<int>(n, 0);

//并查集初始化
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

//并查集寻根
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);   //路径压缩
}

//判断u和v是否同根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

//将v->u加入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}
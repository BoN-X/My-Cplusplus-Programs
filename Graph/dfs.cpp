//深搜三部曲
//1.确认递归函数，参数
//2.确认终止条件
//3.处理目前搜索节点出发的路径

//代码框架
// void dfs(参数) {
//     if (终止条件) {
//         存放结果;
//         return;
//     }
//     for (选择：本节点所连接的其他节点) {
//         处理节点;
//         dfs(图，选择的节点); // 递归
//         回溯，撤销处理结果
//     }
// }

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> result;  //路径集
vector<int> path;   //路径

//邻接矩阵
void dfs(vector<vector<int>>& graph, int x, int n) {
    if (x == n) {
        result.push_back(path);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (graph[x][i] == 1) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();    //回溯，撤销本节点
        }
    }
}

//邻接表
void dfs_list(vector<list<int>>& graph, int x, int n) {
    if (x == n) {
        result.push_back(path);
        return;
    }

    for (int i : graph[x]) {
        path.push_back(i);
        dfs_list(graph, i, n);
        path.pop_back();
    }
}

int main() {
    int n, m, s, t;    //n个节点, m条边
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        cin >> s >> t;
        graph[s][t] = 1;
    }

    path.push_back(1);   //无论如何从第一个节点开始
    dfs(graph, 1, n);

    //输出
    if (result.size() == 0) cout<< -1 << endl;
    for (const vector<int>& pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " "; 
        }
        cout << pa[pa.size() - 1] << endl;
    }
    system("pause");
}
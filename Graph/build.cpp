//图的存储方式
//邻接矩阵和邻接表

#include <iostream>
#include <vector>
#include <list>

int main() {
    int s, t;
    int n = 10, m = 12; //n个节点，m条边
    //邻接矩阵
    std::vector<std::vector<int>> graphA(n + 1, std::vector<int>(n + 1, 0));
    while (m--) {
        std::cin >> s >> t;  //节点s指向节点t
        graphA[s][t] = 1;
    }

    //邻接表
    std::vector<std::list<int>> graphB(n + 1);
    while (m--) {
        std::cin >> s >> t;
        graphB[s].push_back(t);
    }
}
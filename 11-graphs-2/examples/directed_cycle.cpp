#include <iostream>
#include <vector>

using namespace std;

// 0 — вершина не посещена, 1 — находится в текущем стеке DFS,
// 2 — все пути из неё уже обработаны.
bool has_cycle(int v, const vector<vector<int>>& graph, vector<int>& color) {
    color[v] = 1;
    for (int u : graph[v]) {
        if (color[u] == 1) return true;
        if (color[u] == 0 && has_cycle(u, graph, color)) return true;
    }
    color[v] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }

    vector<int> color(n, 0);
    for (int v = 0; v < n; ++v) {
        if (color[v] == 0 && has_cycle(v, graph, color)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}

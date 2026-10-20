#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int edge = 0; edge < m; ++edge) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> used(n, false);
    vector<pair<int, int>> tree_edges;
    queue<int> vertices;
    used[0] = true;
    vertices.push(0);

    while (!vertices.empty()) {
        const int vertex = vertices.front();
        vertices.pop();

        for (int to : graph[vertex]) {
            if (!used[to]) {
                used[to] = true;
                vertices.push(to);
                tree_edges.push_back({vertex, to});
            }
        }
    }

    for (const auto& [from, to] : tree_edges) {
        cout << from + 1 << ' ' << to + 1 << '\n';
    }
}

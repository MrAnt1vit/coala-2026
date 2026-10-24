#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1), reverse_graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> path(k);
    for (int& v : path) cin >> v;

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[path.back()] = 0;
    q.push(path.back());
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : reverse_graph[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    vector<int> shortest_next(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            if (dist[u] == dist[v] + 1) ++shortest_next[u];
        }
    }

    int minimum = 0, maximum = 0;
    for (int i = 0; i + 1 < k; ++i) {
        int u = path[i], v = path[i + 1];
        if (dist[u] != dist[v] + 1) {
            ++minimum;
            ++maximum;
        } else if (shortest_next[u] > 1) {
            ++maximum;
        }
    }
    cout << minimum << ' ' << maximum << '\n';
}

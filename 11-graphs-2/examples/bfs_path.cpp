#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int v = 0; v < n; ++v) {
        for (int u = 0; u < n; ++u) {
            int edge;
            cin >> edge;
            if (edge == 1) graph[v].push_back(u);
        }
    }

    int start, finish;
    cin >> start >> finish;
    --start;
    --finish;

    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            parent[u] = v;
            q.push(u);
        }
    }

    if (dist[finish] == -1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;
    for (int v = finish; v != -1; v = parent[v]) path.push_back(v + 1);
    reverse(path.begin(), path.end());
    cout << dist[finish] << '\n';
    for (int v : path) cout << v << ' ';
    cout << '\n';
}

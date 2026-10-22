#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from;
        --to;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    const long long inf = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n, inf);
    vector<int> parent(n, -1);
    set<pair<long long, int>> frontier;  // {расстояние, вершина}
    dist[0] = 0;
    frontier.insert({0, 0});

    while (!frontier.empty()) {
        int v = frontier.begin()->second;
        frontier.erase(frontier.begin());
        for (auto [u, weight] : graph[v]) {
            if (dist[v] + weight >= dist[u]) continue;
            frontier.erase({dist[u], u});
            dist[u] = dist[v] + weight;
            parent[u] = v;
            frontier.insert({dist[u], u});
        }
    }

    if (dist[n - 1] == inf) {
        cout << -1 << '\n';
    } else {
        vector<int> path;
        for (int v = n - 1; v != -1; v = parent[v]) {
            path.push_back(v + 1);
        }
        reverse(path.begin(), path.end());
        cout << dist[n - 1] << '\n';
        for (int v : path) cout << v << ' ';
        cout << '\n';
    }
}

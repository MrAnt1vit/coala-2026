#include <iostream>
#include <limits>
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
    vector<bool> used(n, false);
    dist[0] = 0;

    for (int step = 0; step < n; ++step) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && dist[i] != inf &&
                (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }
        if (v == -1) break;  // Достижимых необработанных вершин больше нет.
        used[v] = true;
        for (auto [u, weight] : graph[v]) {
            if (dist[v] + weight < dist[u]) dist[u] = dist[v] + weight;
        }
    }

    cout << (dist[n - 1] == inf ? -1 : dist[n - 1]) << '\n';
}

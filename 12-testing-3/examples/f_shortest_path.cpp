#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int start, finish;
    cin >> start >> finish;

    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(start);
    parent[start] = start;
    while (!q.empty() && parent[finish] == -1) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (parent[finish] == -1) {
        cout << "-1\n";
        return 0;
    }
    vector<int> path;
    for (int v = finish; v != start; v = parent[v]) path.push_back(v);
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << '\n';
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
}

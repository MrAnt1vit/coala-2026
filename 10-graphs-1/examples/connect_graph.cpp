#include <iostream>
#include <stack>
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
    vector<int> representatives;

    for (int start = 0; start < n; ++start) {
        if (used[start]) {
            continue;
        }

        representatives.push_back(start);
        stack<int> vertices;
        vertices.push(start);
        used[start] = true;

        while (!vertices.empty()) {
            const int vertex = vertices.top();
            vertices.pop();
            for (int to : graph[vertex]) {
                if (!used[to]) {
                    used[to] = true;
                    vertices.push(to);
                }
            }
        }
    }

    cout << representatives.size() - 1 << '\n';
    for (int i = 1; i < static_cast<int>(representatives.size()); ++i) {
        cout << representatives[i - 1] + 1 << ' '
             << representatives[i] + 1 << '\n';
    }
}

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
    vector<vector<int>> components;

    for (int start = 0; start < n; ++start) {
        if (used[start]) {
            continue;
        }

        components.push_back({});
        stack<int> vertices;
        vertices.push(start);
        used[start] = true;

        while (!vertices.empty()) {
            const int vertex = vertices.top();
            vertices.pop();
            components.back().push_back(vertex);

            for (int to : graph[vertex]) {
                if (!used[to]) {
                    used[to] = true;
                    vertices.push(to);
                }
            }
        }
    }

    cout << components.size() << '\n';
    for (const vector<int>& component : components) {
        cout << component.size() << '\n';
        for (int vertex : component) {
            cout << vertex + 1 << ' ';
        }
        cout << '\n';
    }
}

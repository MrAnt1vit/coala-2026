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

    if (m != n - 1) {
        cout << "NO\n";
        return 0;
    }

    vector<bool> used(n, false);
    stack<int> vertices;
    vertices.push(0);
    used[0] = true;
    int visited_count = 0;

    while (!vertices.empty()) {
        const int vertex = vertices.top();
        vertices.pop();
        ++visited_count;

        for (int to : graph[vertex]) {
            if (!used[to]) {
                used[to] = true;
                vertices.push(to);
            }
        }
    }

    cout << (visited_count == n ? "YES" : "NO") << '\n';
}

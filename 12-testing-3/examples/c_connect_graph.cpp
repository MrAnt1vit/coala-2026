#include <iostream>
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
        graph[v].push_back(u);
    }

    vector<char> seen(n + 1, false);
    vector<int> representatives;
    for (int start = 1; start <= n; ++start) {
        if (seen[start]) continue;
        representatives.push_back(start);
        vector<int> stack = {start};
        seen[start] = true;
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            for (int v : graph[u]) {
                if (!seen[v]) {
                    seen[v] = true;
                    stack.push_back(v);
                }
            }
        }
    }

    cout << representatives.size() - 1 << '\n';
    for (size_t i = 1; i < representatives.size(); ++i) {
        cout << representatives[0] << ' ' << representatives[i] << '\n';
    }
}

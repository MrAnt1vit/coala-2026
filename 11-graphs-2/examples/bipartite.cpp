#include <iostream>
#include <vector>

using namespace std;

bool paint(int v, int assigned, const vector<vector<int>>& graph,
           vector<int>& color) {
    color[v] = assigned;
    for (int u : graph[v]) {
        if (color[u] == assigned) return false;
        if (color[u] == 0 && !paint(u, 3 - assigned, graph, color)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> color(n, 0);
    for (int v = 0; v < n; ++v) {
        if (color[v] == 0 && !paint(v, 1, graph, color)) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> group;
    for (int v = 0; v < n; ++v) {
        if (color[v] == 1) group.push_back(v + 1);
    }
    cout << "YES\n" << group.size() << '\n';
    for (int v : group) cout << v << ' ';
    cout << '\n';
}

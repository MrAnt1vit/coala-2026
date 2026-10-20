#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start;
    cin >> n >> start;
    --start;

    vector<vector<int>> graph(n);
    for (int from = 0; from < n; ++from) {
        for (int to = 0; to < n; ++to) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                graph[from].push_back(to);
            }
        }
    }

    vector<bool> used(n, false);
    queue<int> vertices;
    used[start] = true;
    vertices.push(start);
    int reachable_count = 0;

    while (!vertices.empty()) {
        const int vertex = vertices.front();
        vertices.pop();
        ++reachable_count;

        for (int to : graph[vertex]) {
            if (!used[to]) {
                used[to] = true;
                vertices.push(to);
            }
        }
    }

    cout << reachable_count << '\n';
}

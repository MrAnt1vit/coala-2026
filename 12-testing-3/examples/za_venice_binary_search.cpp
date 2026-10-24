#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int islands, bridges;
    cin >> islands >> bridges;
    vector<vector<pair<int, int>>> graph(islands + 1);
    int max_height = 0;
    for (int i = 0; i < bridges; ++i) {
        int u, v, height;
        cin >> u >> v >> height;
        graph[u].push_back({v, height});
        graph[v].push_back({u, height});
        if (height > max_height) max_height = height;
    }

    auto connected = [&](int threshold) {
        vector<char> seen(islands + 1, false);
        queue<int> q;
        q.push(1);
        seen[1] = true;
        int count = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, height] : graph[u]) {
                if (height >= threshold && !seen[v]) {
                    seen[v] = true;
                    ++count;
                    q.push(v);
                }
            }
        }
        return count == islands;
    };

    int good = 0, bad = max_height + 1;
    while (bad - good > 1) {
        int middle = good + (bad - good) / 2;
        if (connected(middle)) good = middle;
        else bad = middle;
    }
    cout << good << '\n';
}

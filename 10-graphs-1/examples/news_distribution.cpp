#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, group_count;
    cin >> n >> group_count;
    vector<vector<int>> graph(n);

    for (int group = 0; group < group_count; ++group) {
        int size;
        cin >> size;
        if (size == 0) {
            continue;
        }

        int first;
        cin >> first;
        --first;
        for (int i = 1; i < size; ++i) {
            int member;
            cin >> member;
            --member;
            graph[first].push_back(member);
            graph[member].push_back(first);
        }
    }

    vector<int> component_size(n, 0);
    vector<bool> used(n, false);

    for (int start = 0; start < n; ++start) {
        if (used[start]) {
            continue;
        }

        vector<int> component;
        queue<int> vertices;
        used[start] = true;
        vertices.push(start);

        while (!vertices.empty()) {
            const int vertex = vertices.front();
            vertices.pop();
            component.push_back(vertex);

            for (int to : graph[vertex]) {
                if (!used[to]) {
                    used[to] = true;
                    vertices.push(to);
                }
            }
        }

        for (int vertex : component) {
            component_size[vertex] = static_cast<int>(component.size());
        }
    }

    for (int vertex = 0; vertex < n; ++vertex) {
        cout << component_size[vertex] << (vertex + 1 == n ? '\n' : ' ');
    }
}

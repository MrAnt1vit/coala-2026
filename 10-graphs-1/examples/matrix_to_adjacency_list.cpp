#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
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

    for (const vector<int>& neighbors : graph) {
        cout << neighbors.size();
        for (int vertex : neighbors) {
            cout << ' ' << vertex + 1;
        }
        cout << '\n';
    }
}

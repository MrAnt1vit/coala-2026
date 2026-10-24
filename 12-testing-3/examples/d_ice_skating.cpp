#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> point(n);
    for (auto& [x, y] : point) cin >> x >> y;

    vector<char> seen(n, false);
    int components = 0;
    for (int start = 0; start < n; ++start) {
        if (seen[start]) continue;
        ++components;
        vector<int> stack = {start};
        seen[start] = true;
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            for (int v = 0; v < n; ++v) {
                if (!seen[v] && (point[u].first == point[v].first ||
                                 point[u].second == point[v].second)) {
                    seen[v] = true;
                    stack.push_back(v);
                }
            }
        }
    }
    cout << components - 1 << '\n';
}

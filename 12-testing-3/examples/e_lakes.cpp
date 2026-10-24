#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> depth(n, vector<int>(m));
        for (auto& row : depth) for (int& value : row) cin >> value;

        long long best = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (depth[r][c] == 0) continue;
                long long volume = depth[r][c];
                vector<pair<int, int>> stack = {{r, c}};
                depth[r][c] = 0;
                while (!stack.empty()) {
                    auto [x, y] = stack.back();
                    stack.pop_back();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dr[d], ny = y + dc[d];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                            depth[nx][ny] > 0) {
                            volume += depth[nx][ny];
                            depth[nx][ny] = 0;
                            stack.push_back({nx, ny});
                        }
                    }
                }
                best = max(best, volume);
            }
        }
        cout << best << '\n';
    }
}

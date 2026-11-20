#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    if (!(std::cin >> a >> b)) return 0;
    const int n = static_cast<int>(a.size());
    const int m = static_cast<int>(b.size());
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) dist[i][0] = i;
    for (int j = 0; j <= m; ++j) dist[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dist[i][j] = std::min({
                dist[i - 1][j] + 1,
                dist[i][j - 1] + 1,
                dist[i - 1][j - 1] + (a[i - 1] != b[j - 1])
            });
        }
    }
    std::cout << dist[n][m] << '\n';
}

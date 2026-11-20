#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;
    std::vector<std::vector<long long>> a(n, std::vector<long long>(m));
    for (auto& row : a)
        for (auto& cell : row) std::cin >> cell;

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m));
    dp[0][0] = a[0][0];
    for (int j = 1; j < m; ++j) dp[0][j] = dp[0][j - 1] + a[0][j];
    for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + a[i][0];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = a[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);

    std::cout << dp[n - 1][m - 1] << '\n';
}

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1), pred(n + 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        pred[i] = i - 1;
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            pred[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            pred[i] = i / 3;
        }
    }

    std::vector<int> path;
    for (int x = n; x != 1; x = pred[x]) path.push_back(x);
    path.push_back(1);
    std::reverse(path.begin(), path.end());

    std::cout << dp[n] << '\n';
    for (std::size_t i = 0; i < path.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << path[i];
    }
    std::cout << '\n';
}

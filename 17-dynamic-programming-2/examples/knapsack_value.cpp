#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, capacity;
    if (!(std::cin >> n >> capacity)) return 0;
    std::vector<int> weight(n), value(n);
    for (int& x : weight) std::cin >> x;
    for (int& x : value) std::cin >> x;

    const long long neg = -(1LL << 60);
    std::vector<std::vector<long long>> dp(
        n + 1, std::vector<long long>(capacity + 1, neg));
    std::vector<std::vector<char>> take(
        n + 1, std::vector<char>(capacity + 1, false));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int total = 0; total <= capacity; ++total) {
            dp[i][total] = dp[i - 1][total];
            int before = total - weight[i - 1];
            if (before >= 0 && dp[i - 1][before] != neg &&
                dp[i - 1][before] + value[i - 1] > dp[i][total]) {
                dp[i][total] = dp[i - 1][before] + value[i - 1];
                take[i][total] = true;
            }
        }
    }

    int best_weight = 0;
    for (int total = 1; total <= capacity; ++total)
        if (dp[n][total] > dp[n][best_weight]) best_weight = total;

    std::cout << dp[n][best_weight] << '\n';
    std::vector<int> chosen;
    int total = best_weight;
    for (int i = n; i >= 1; --i) {
        if (take[i][total]) {
            chosen.push_back(i);
            total -= weight[i - 1];
        }
    }
    std::reverse(chosen.begin(), chosen.end());
    std::cout << chosen.size() << '\n';
    for (int i : chosen) std::cout << i << ' ';
    std::cout << '\n';
}

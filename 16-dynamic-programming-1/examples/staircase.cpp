#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = a[i] + std::max(dp[i - 1], dp[i - 2]);
    }

    std::cout << dp[n] << '\n';
}

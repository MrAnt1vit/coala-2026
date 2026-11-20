#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> dp(n + 1);
    dp[1] = 1;
    if (n >= 2) dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[n] << '\n';
}

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    if (n >= 1) dp[1] = 2;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[n] << '\n';
}

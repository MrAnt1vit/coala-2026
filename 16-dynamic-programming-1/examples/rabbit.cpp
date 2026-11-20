#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    int n;
    std::string cells;
    std::cin >> n >> cells;

    const long long impossible = std::numeric_limits<long long>::min() / 4;
    std::vector<long long> dp(n, impossible);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        if (cells[i] == 'w') continue;
        for (int jump : {1, 3, 5}) {
            if (i < jump || dp[i - jump] == impossible) continue;
            dp[i] = std::max(dp[i], dp[i - jump] + (cells[i] == '"'));
        }
    }

    if (dp[n - 1] == impossible) std::cout << -1 << '\n';
    else std::cout << dp[n - 1] << '\n';
}

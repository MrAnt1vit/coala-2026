#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n < 0) return 0;

    std::vector<char> is_prime(n + 1, true);
    is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) ++count;
    }
    std::cout << count << '\n';
    bool first = true;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        if (!first) std::cout << ' ';
        std::cout << i;
        first = false;
    }
    std::cout << '\n';
}

#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;
    const int neg = -1000000000;
    std::array<int, 3> previous{0, neg, neg};
    for (int day = 0; day < n; ++day) {
        int available;
        std::cin >> available;
        std::array<int, 3> current{neg, neg, neg};
        current[0] = std::max({previous[0], previous[1], previous[2]});
        if (available == 2 || available == 3)
            current[1] = 1 + std::max(previous[0], previous[2]);
        if (available == 1 || available == 3)
            current[2] = 1 + std::max(previous[0], previous[1]);
        previous = current;
    }
    std::cout << n - std::max({previous[0], previous[1], previous[2]}) << '\n';
}

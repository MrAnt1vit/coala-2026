#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int capacity, n;
    if (!(std::cin >> capacity >> n)) return 0;
    std::vector<int> weight(n);
    for (int& x : weight) std::cin >> x;

    std::vector<char> possible(capacity + 1, false);
    possible[0] = true;
    for (int item : weight) {
        for (int total = capacity; total >= item; --total)
            if (possible[total - item]) possible[total] = true;
    }
    for (int total = capacity; total >= 0; --total) {
        if (possible[total]) {
            std::cout << total << '\n';
            break;
        }
    }
}

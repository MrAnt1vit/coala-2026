#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string recipe;
    cin >> recipe;

    array<long long, 3> have{};
    array<long long, 3> price{};
    for (long long& value : have) {
        cin >> value;
    }
    for (long long& value : price) {
        cin >> value;
    }

    long long rubles;
    cin >> rubles;

    array<long long, 3> need{};
    for (char ingredient : recipe) {
        if (ingredient == 'B') ++need[0];
        if (ingredient == 'S') ++need[1];
        if (ingredient == 'C') ++need[2];
    }

    auto can_make = [&](long long count) {
        __int128 cost = 0;
        for (int product = 0; product < 3; ++product) {
            const __int128 required =
                static_cast<__int128>(need[product]) * count;
            if (required > have[product]) {
                cost += (required - have[product]) * price[product];
            }
        }
        return cost <= rubles;
    };

    long long left = 0;
    long long right = 1;
    while (can_make(right)) {
        right *= 2;
    }

    while (right - left > 1) {
        const long long middle = left + (right - left) / 2;
        if (can_make(middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }

    cout << left << '\n';
}

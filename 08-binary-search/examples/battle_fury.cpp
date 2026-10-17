#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target_damage, splash_damage;
    cin >> n >> target_damage >> splash_damage;

    vector<long long> health(n);
    for (long long& value : health) {
        cin >> value;
    }

    auto enough_hits = [&](long long hits) {
        long long base_damage = splash_damage * hits;
        if (target_damage == splash_damage) {
            for (long long value : health) {
                if (base_damage < value) {
                    return false;
                }
            }
            return true;
        }

        long long extra_damage = target_damage - splash_damage;
        long long aimed_hits = 0;
        for (long long value : health) {
            if (value > base_damage) {
                long long remaining = value - base_damage;
                aimed_hits += (remaining + extra_damage - 1) / extra_damage;
                if (aimed_hits > hits) {
                    return false;
                }
            }
        }
        return true;
    };

    long long left = -1;
    long long right = 1;
    while (!enough_hits(right)) {
        right *= 2;
    }

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (enough_hits(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << '\n';
}


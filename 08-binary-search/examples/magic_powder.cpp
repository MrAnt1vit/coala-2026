#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long powder;
    cin >> n >> powder;

    vector<long long> need(n), have(n);
    long long total_need = 0;
    long long total_have = 0;
    for (long long& value : need) {
        cin >> value;
        total_need += value;
    }
    for (long long& value : have) {
        cin >> value;
        total_have += value;
    }

    auto can_bake = [&](long long cookies) {
        long long missing = 0;
        for (int i = 0; i < n; ++i) {
            long long required = need[i] * cookies;
            if (required > have[i]) {
                missing += required - have[i];
                if (missing > powder) {
                    return false;
                }
            }
        }
        return true;
    };

    long long left = 0;
    long long right = (total_have + powder) / total_need + 1;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (can_bake(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << '\n';
}


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, required_cows;
    cin >> n >> required_cows;

    vector<long long> stalls(n);
    for (long long& coordinate : stalls) {
        cin >> coordinate;
    }
    sort(stalls.begin(), stalls.end());

    auto can_place = [&](long long distance) {
        int placed = 1;
        long long last = stalls.front();
        for (int i = 1; i < n; ++i) {
            if (stalls[i] - last >= distance) {
                ++placed;
                last = stalls[i];
            }
        }
        return placed >= required_cows;
    };

    long long left = 0;
    long long right = stalls.back() - stalls.front() + 1;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (can_place(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << '\n';
}


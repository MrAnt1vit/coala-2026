#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (long long& value : a) {
        cin >> value;
    }

    while (q--) {
        long long x;
        cin >> x;

        auto lower = lower_bound(a.begin(), a.end(), x);
        auto upper = upper_bound(a.begin(), a.end(), x);

        long long count = upper - lower;
        long long first = -1;
        long long last = -1;
        if (count > 0) {
            first = lower - a.begin();
            last = upper - a.begin() - 1;
        }

        long long nearest;
        if (lower == a.begin()) {
            nearest = *lower;
        } else if (lower == a.end()) {
            nearest = a.back();
        } else {
            long long right_value = *lower;
            long long left_value = *(lower - 1);
            long long left_distance = llabs(x - left_value);
            long long right_distance = llabs(right_value - x);
            nearest = (left_distance <= right_distance ? left_value : right_value);
        }

        cout << first << ' ' << last << ' ' << count << ' ' << nearest << '\n';
    }
}


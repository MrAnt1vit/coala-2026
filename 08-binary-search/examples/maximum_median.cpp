#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long operations;
    cin >> n >> operations;

    vector<long long> a(n);
    for (long long& value : a) {
        cin >> value;
    }
    sort(a.begin(), a.end());

    int middle = n / 2;
    auto achievable = [&](long long median) {
        long long cost = 0;
        for (int i = middle; i < n; ++i) {
            if (a[i] < median) {
                cost += median - a[i];
                if (cost > operations) {
                    return false;
                }
            }
        }
        return true;
    };

    long long left = a[middle];
    long long right = a[middle] + operations + 1;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (achievable(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << '\n';
}


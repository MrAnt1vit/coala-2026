#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> height(n);
    for (long long& value : height) {
        cin >> value;
    }

    long long window_sum = 0;
    for (int i = 0; i < k; ++i) {
        window_sum += height[i];
    }

    long long best_sum = window_sum;
    int best_left = 0;

    for (int right = k; right < n; ++right) {
        window_sum += height[right] - height[right - k];
        if (window_sum < best_sum) {
            best_sum = window_sum;
            best_left = right - k + 1;
        }
    }

    cout << best_left + 1 << '\n';
}

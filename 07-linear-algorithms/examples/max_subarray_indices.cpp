#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long value;
        cin >> value;
        prefix[i + 1] = prefix[i] + value;
    }

    long long best_sum = numeric_limits<long long>::lowest();
    long long minimum_prefix = prefix[0];
    int minimum_position = 0;
    int answer_left = 0;
    int answer_right = 0;

    for (int right = 1; right <= n; ++right) {
        const long long current_sum = prefix[right] - minimum_prefix;
        if (current_sum > best_sum) {
            best_sum = current_sum;
            answer_left = minimum_position;
            answer_right = right - 1;
        }

        if (prefix[right] <= minimum_prefix) {
            minimum_prefix = prefix[right];
            minimum_position = right;
        }
    }

    cout << answer_left + 1 << ' ' << answer_right + 1 << '\n';
}

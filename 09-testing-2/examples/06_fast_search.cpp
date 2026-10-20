#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> values(n);
    for (long long& value : values) {
        cin >> value;
    }
    sort(values.begin(), values.end());

    int query_count;
    cin >> query_count;
    for (int query = 0; query < query_count; ++query) {
        long long left_value, right_value;
        cin >> left_value >> right_value;

        const auto left = lower_bound(values.begin(), values.end(), left_value);
        const auto right = upper_bound(values.begin(), values.end(), right_value);
        cout << right - left << (query + 1 == query_count ? '\n' : ' ');
    }
}

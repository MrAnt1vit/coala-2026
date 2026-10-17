#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long time_limit;
    cin >> n >> time_limit;

    vector<long long> reading_time(n);
    for (long long& value : reading_time) {
        cin >> value;
    }

    int answer = 0;
    int left = 0;
    long long window_sum = 0;

    for (int right = 0; right < n; ++right) {
        window_sum += reading_time[right];
        while (window_sum > time_limit) {
            window_sum -= reading_time[left];
            ++left;
        }
        answer = max(answer, right - left + 1);
    }

    cout << answer << '\n';
}

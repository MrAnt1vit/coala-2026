#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long start_x, start_y, target_x, target_y;
    cin >> start_x >> start_y >> target_x >> target_y;

    int n;
    string wind;
    cin >> n >> wind;

    vector<long long> prefix_x(n + 1, 0), prefix_y(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_x[i + 1] = prefix_x[i];
        prefix_y[i + 1] = prefix_y[i];
        if (wind[i] == 'L') --prefix_x[i + 1];
        if (wind[i] == 'R') ++prefix_x[i + 1];
        if (wind[i] == 'D') --prefix_y[i + 1];
        if (wind[i] == 'U') ++prefix_y[i + 1];
    }

    auto can_reach = [&](long long days) {
        long long full_cycles = days / n;
        int remainder = static_cast<int>(days % n);

        long long wind_x = full_cycles * prefix_x[n] + prefix_x[remainder];
        long long wind_y = full_cycles * prefix_y[n] + prefix_y[remainder];
        long long current_x = start_x + wind_x;
        long long current_y = start_y + wind_y;
        long long distance = current_x >= target_x ? current_x - target_x
                                                    : target_x - current_x;
        distance += current_y >= target_y ? current_y - target_y
                                           : target_y - current_y;
        return distance <= days;
    };

    const long long limit = 4'000'000'000'000'000'000LL;
    if (!can_reach(limit)) {
        cout << -1 << '\n';
        return 0;
    }

    long long left = -1;
    long long right = limit;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (can_reach(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << '\n';
}


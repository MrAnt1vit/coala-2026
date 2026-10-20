#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x, y;
    cin >> n >> x >> y;

    const long long first_copy_time = min(x, y);
    if (n == 1) {
        cout << first_copy_time << '\n';
        return 0;
    }

    auto enough = [&](long long time) {
        return time / x + time / y >= n - 1;
    };

    long long left = -1;
    long long right = min(x, y) * (n - 1);
    while (right - left > 1) {
        const long long middle = left + (right - left) / 2;
        if (enough(middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }

    cout << first_copy_time + right << '\n';
}

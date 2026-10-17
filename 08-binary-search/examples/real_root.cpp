#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double target;
    cin >> target;

    double left = 0.0;
    double right = max(1.0, sqrt(target) + 1.0);

    for (int iteration = 0; iteration < 100; ++iteration) {
        double mid = (left + right) / 2.0;
        double value = mid * mid + sqrt(mid);
        if (value >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed << setprecision(10) << (left + right) / 2.0 << '\n';
}


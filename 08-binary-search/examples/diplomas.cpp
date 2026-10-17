#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long width, height, count;
    cin >> width >> height >> count;

    auto fits = [&](long long side) {
        long long columns = side / width;
        long long rows = side / height;
        if (columns == 0 || rows == 0) {
            return false;
        }
        return columns >= (count + rows - 1) / rows;
    };

    long long left = 0;
    long long right = 1;
    while (!fits(right)) {
        right *= 2;
    }

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (fits(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << '\n';
}


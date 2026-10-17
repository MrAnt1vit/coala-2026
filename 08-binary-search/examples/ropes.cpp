#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long required;
    cin >> n >> required;

    vector<long long> lengths(n);
    for (long long& length : lengths) {
        cin >> length;
    }

    auto enough = [&](long long piece_length) {
        long long pieces = 0;
        for (long long length : lengths) {
            pieces += length / piece_length;
            if (pieces >= required) {
                return true;
            }
        }
        return false;
    };

    long long left = 0;
    long long right = *max_element(lengths.begin(), lengths.end()) + 1;

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (enough(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << '\n';
}


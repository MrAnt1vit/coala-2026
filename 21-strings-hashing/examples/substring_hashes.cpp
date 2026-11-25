#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t, r;
    string s;
    cin >> t >> r >> s;
    int n = static_cast<int>(s.size());
    vector<long long> h(n + 1), power(n + 1);
    power[0] = 1;
    for (int i = 0; i < n; ++i) {
        h[i + 1] = (h[i] * t + static_cast<unsigned char>(s[i])) % r;
        power[i + 1] = power[i] * t % r;
    }

    int m;
    cin >> m;
    while (m--) {
        int left, right;
        cin >> left >> right;  // В условии границы включительные, индексация с нуля.
        int len = right - left + 1;
        cout << (h[right + 1] - h[left] * power[len] % r + r) % r << '\n';
    }
}

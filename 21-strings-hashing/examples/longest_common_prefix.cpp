#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long T = 31, MOD = 1000000007;
vector<long long> h, power_t;

void precalc(const string& s) {
    h.assign(s.size() + 1, 0);
    power_t.assign(s.size() + 1, 0);
    power_t[0] = 1;
    for (size_t i = 0; i < s.size(); ++i) {
        h[i + 1] = (h[i] * T + static_cast<unsigned char>(s[i])) % MOD;
        power_t[i + 1] = power_t[i] * T % MOD;
    }
}

long long get_hash(int left, int right) {  // [left, right)
    return (h[right] - h[left] * power_t[right - left] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    precalc(s);
    int n = static_cast<int>(s.size());
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;  // Нумерация с нуля: сравниваются суффиксы s[x..] и s[y..].
        int low = 0;
        int high = min(n - x, n - y) + 1;  // Искусственная граница за ответом.
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get_hash(x, x + mid) == get_hash(y, y + mid)) low = mid;
            else high = mid;
        }
        cout << low << '\n';
    }
}

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
    int m;
    cin >> m;
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;  // Нумерация с единицы, оба конца включены.
        cout << (b - a == d - c && get_hash(a - 1, b) == get_hash(c - 1, d)
                     ? "Yes\n" : "No\n");
    }
}

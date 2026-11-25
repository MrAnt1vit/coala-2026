#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const long long T1 = 31, MOD1 = 1000000007;
const long long T2 = 29, MOD2 = 1000000009;
vector<long long> h1, h2, power1, power2;

void precalc(const string& s) {
    int n = static_cast<int>(s.size());
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    power1.assign(n + 1, 0);
    power2.assign(n + 1, 0);
    power1[0] = power2[0] = 1;
    for (int i = 0; i < n; ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        h1[i + 1] = (h1[i] * T1 + c) % MOD1;
        h2[i + 1] = (h2[i] * T2 + c) % MOD2;
        power1[i + 1] = power1[i] * T1 % MOD1;
        power2[i + 1] = power2[i] * T2 % MOD2;
    }
}

pair<long long, long long> get_hash(int left, int right) {  // [left, right)
    int len = right - left;
    return {
        (h1[right] - h1[left] * power1[len] % MOD1 + MOD1) % MOD1,
        (h2[right] - h2[left] * power2[len] % MOD2 + MOD2) % MOD2
    };
}

pair<long long, long long> whole_hash(const string& pattern) {
    long long x = 0, y = 0;
    for (unsigned char c : pattern) {
        x = (x * T1 + c) % MOD1;
        y = (y * T2 + c) % MOD2;
    }
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern, text;
    cin >> pattern >> text;
    auto wanted = whole_hash(pattern);
    precalc(text);

    vector<int> answer;
    for (size_t i = 0; i + pattern.size() <= text.size(); ++i) {
        if (get_hash(static_cast<int>(i), static_cast<int>(i + pattern.size())) == wanted) {
            answer.push_back(static_cast<int>(i) + 1);
        }
    }
    cout << answer.size() << '\n';
    for (int position : answer) cout << position << ' ';
    cout << '\n';
}

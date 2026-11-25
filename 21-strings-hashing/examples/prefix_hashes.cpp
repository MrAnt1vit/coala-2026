#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t, r;
    string s;
    cin >> t >> r >> s;

    long long h = 0;
    for (char c : s) {
        h = (h * t + static_cast<unsigned char>(c)) % r;
        cout << h << '\n';
    }
}

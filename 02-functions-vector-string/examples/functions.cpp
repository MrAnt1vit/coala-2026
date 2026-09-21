#include <iostream>

using namespace std;

int square(int x) {
    return x * x;
}

void solve() {
    int x;
    cin >> x;
    cout << square(x) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

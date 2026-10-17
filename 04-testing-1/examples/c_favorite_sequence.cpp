#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> board(n);
    for (int& value : board) {
        cin >> value;
    }

    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << board[left++] << ' ';
        } else {
            cout << board[right--] << ' ';
        }
    }
    cout << '\n';
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}

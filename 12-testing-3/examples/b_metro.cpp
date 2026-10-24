#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> forward(n + 1), backward(n + 1);
    for (int i = 1; i <= n; ++i) cin >> forward[i];
    for (int i = 1; i <= n; ++i) cin >> backward[i];

    bool possible = false;
    if (forward[1]) {
        possible = forward[target];
        if (!possible && backward[target]) {
            for (int i = target + 1; i <= n; ++i) {
                if (forward[i] && backward[i]) possible = true;
            }
        }
    }
    cout << (possible ? "YES" : "NO") << '\n';
}

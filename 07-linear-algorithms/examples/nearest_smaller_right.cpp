#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> price(n);
    for (long long& value : price) {
        cin >> value;
    }

    vector<int> answer(n, -1);
    stack<int> candidates;

    for (int i = n - 1; i >= 0; --i) {
        while (!candidates.empty() && price[candidates.top()] >= price[i]) {
            candidates.pop();
        }
        if (!candidates.empty()) {
            answer[i] = candidates.top();
        }
        candidates.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
}

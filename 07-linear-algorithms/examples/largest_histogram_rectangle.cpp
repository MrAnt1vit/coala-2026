#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> height(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    stack<int> increasing;
    long long answer = 0;

    for (int right = 0; right <= n; ++right) {
        while (!increasing.empty() && height[increasing.top()] >= height[right]) {
            const int middle = increasing.top();
            increasing.pop();
            const int left = increasing.empty() ? -1 : increasing.top();
            const long long width = right - left - 1LL;
            answer = max(answer, height[middle] * width);
        }
        increasing.push(right);
    }

    cout << answer << '\n';
}

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, window_size;
    cin >> n >> window_size;
    vector<long long> values(n);
    for (long long& value : values) {
        cin >> value;
    }

    deque<int> candidates;
    for (int i = 0; i < n; ++i) {
        while (!candidates.empty() && candidates.front() <= i - window_size) {
            candidates.pop_front();
        }
        while (!candidates.empty() && values[candidates.back()] >= values[i]) {
            candidates.pop_back();
        }
        candidates.push_back(i);

        if (i + 1 >= window_size) {
            cout << values[candidates.front()] << '\n';
        }
    }
}

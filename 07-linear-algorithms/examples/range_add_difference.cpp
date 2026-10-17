#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> difference(n + 1, 0);
    long long previous = 0;
    for (int i = 0; i < n; ++i) {
        long long current;
        cin >> current;
        difference[i] = current - previous;
        previous = current;
    }

    int query_count;
    cin >> query_count;
    while (query_count-- > 0) {
        int left, right;
        long long add;
        cin >> left >> right >> add;
        --left;
        --right;
        difference[left] += add;
        difference[right + 1] -= add;
    }

    long long current = 0;
    for (int i = 0; i < n; ++i) {
        current += difference[i];
        cout << current << (i + 1 == n ? '\n' : ' ');
    }
}

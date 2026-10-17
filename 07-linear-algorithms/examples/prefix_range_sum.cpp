#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long value;
        cin >> value;
        prefix[i + 1] = prefix[i] + value;
    }

    int query_count;
    cin >> query_count;
    while (query_count-- > 0) {
        int left, right;
        cin >> left >> right;
        --left;
        cout << prefix[right] - prefix[left] << '\n';
    }
}

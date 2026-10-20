#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_count;
    cin >> test_count;

    while (test_count-- > 0) {
        int n;
        cin >> n;
        vector<int> price(n);
        for (int& value : price) {
            cin >> value;
        }

        int suffix_minimum = price.back();
        int bad_count = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (price[i] > suffix_minimum) {
                ++bad_count;
            }
            suffix_minimum = min(suffix_minimum, price[i]);
        }

        cout << bad_count << '\n';
    }
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> prices(n);
    for (int& price : prices) {
        cin >> price;
    }
    sort(prices.begin(), prices.end());

    int q;
    cin >> q;
    while (q--) {
        int money;
        cin >> money;
        cout << upper_bound(prices.begin(), prices.end(), money) - prices.begin() << '\n';
    }
}


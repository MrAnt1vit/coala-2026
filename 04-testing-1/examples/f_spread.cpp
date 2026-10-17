#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int& value : values) {
        cin >> value;
    }

    int minimum = *min_element(values.begin(), values.end());
    int maximum = *max_element(values.begin(), values.end());
    vector<int> count(maximum - minimum + 1, 0);

    for (int value : values) {
        count[value - minimum]++;
    }

    for (int offset = 0; offset < static_cast<int>(count.size()); offset++) {
        while (count[offset] > 0) {
            cout << minimum + offset << ' ';
            count[offset]--;
        }
    }
    cout << '\n';
}

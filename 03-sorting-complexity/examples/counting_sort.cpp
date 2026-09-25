#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(const vector<int>& a) {
    if (a.empty()) {
        return {};
    }

    int minimum = *min_element(a.begin(), a.end());
    int maximum = *max_element(a.begin(), a.end());
    vector<int> count(maximum - minimum + 1);

    for (int value : a) {
        count[value - minimum]++;
    }

    vector<int> result;
    for (int index = 0; index < static_cast<int>(count.size()); index++) {
        for (int times = 0; times < count[index]; times++) {
            result.push_back(index + minimum);
        }
    }
    return result;
}

int main() {
    vector<int> a = {3, -1, 3, 2, -2, 0};
    vector<int> sorted = counting_sort(a);

    for (int value : sorted) {
        cout << value << ' ';
    }
    cout << '\n';
}

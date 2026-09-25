#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& a) {
    for (int last = static_cast<int>(a.size()) - 1; last > 0; last--) {
        int max_index = 0;
        for (int i = 1; i <= last; i++) {
            if (a[i] > a[max_index]) {
                max_index = i;
            }
        }
        swap(a[max_index], a[last]);
    }
}

int main() {
    vector<int> a = {3, 1, 8, 2, 10};
    selection_sort(a);

    for (int value : a) {
        cout << value << ' ';
    }
    cout << '\n';
}

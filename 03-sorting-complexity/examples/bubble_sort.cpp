#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& a) {
    for (int last = static_cast<int>(a.size()) - 1; last > 0; last--) {
        bool changed = false;
        for (int i = 0; i < last; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }
}

int main() {
    vector<int> a = {3, 1, 8, 2, 10};
    bubble_sort(a);

    for (int value : a) {
        cout << value << ' ';
    }
    cout << '\n';
}

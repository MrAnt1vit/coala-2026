#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& a) {
    for (int i = 1; i < static_cast<int>(a.size()); i++) {
        int value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}

int main() {
    vector<int> a = {3, 1, 8, 2, 10};
    insertion_sort(a);

    for (int value : a) {
        cout << value << ' ';
    }
    cout << '\n';
}

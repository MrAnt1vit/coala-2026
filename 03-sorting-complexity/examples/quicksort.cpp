#include <iostream>
#include <vector>

using namespace std;

vector<int> quicksort(const vector<int>& a) {
    if (a.size() <= 1) {
        return a;
    }

    int pivot = a[a.size() / 2];
    vector<int> less;
    vector<int> equal;
    vector<int> greater;

    for (int value : a) {
        if (value < pivot) {
            less.push_back(value);
        } else if (value > pivot) {
            greater.push_back(value);
        } else {
            equal.push_back(value);
        }
    }

    vector<int> result = quicksort(less);
    vector<int> sorted_greater = quicksort(greater);
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), sorted_greater.begin(), sorted_greater.end());
    return result;
}

int main() {
    vector<int> a = {3, 1, 8, 2, 10, 3};
    vector<int> sorted = quicksort(a);

    for (int value : sorted) {
        cout << value << ' ';
    }
    cout << '\n';
}

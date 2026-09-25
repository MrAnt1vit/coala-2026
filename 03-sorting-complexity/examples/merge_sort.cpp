#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0;
    int j = 0;

    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < static_cast<int>(left.size())) {
        result.push_back(left[i]);
        i++;
    }
    while (j < static_cast<int>(right.size())) {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

vector<int> merge_sort(const vector<int>& a) {
    if (a.size() <= 1) {
        return a;
    }

    int middle = static_cast<int>(a.size()) / 2;
    vector<int> left(a.begin(), a.begin() + middle);
    vector<int> right(a.begin() + middle, a.end());
    return merge(merge_sort(left), merge_sort(right));
}

int main() {
    vector<int> a = {3, 1, 8, 2, 10};
    vector<int> sorted = merge_sort(a);

    for (int value : sorted) {
        cout << value << ' ';
    }
    cout << '\n';
}

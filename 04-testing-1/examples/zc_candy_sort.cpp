#include <cstddef>
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

    const size_t side = static_cast<size_t>(n) + 1;
    vector<unsigned char> forbidden(side * side, 0);
    auto index = [side](int first, int second) {
        return static_cast<size_t>(first) * side + second;
    };

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;
        forbidden[index(first, second)] = 1;
        forbidden[index(second, first)] = 1;
    }

    for (int pass = 0; pass < n - 1; pass++) {
        bool changed = false;
        for (int i = 0; i + 1 < n; i++) {
            if (values[i] > values[i + 1] &&
                !forbidden[index(values[i], values[i + 1])]) {
                swap(values[i], values[i + 1]);
                changed = true;
            }
        }
        if (!changed) {
            break;
        }
    }

    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

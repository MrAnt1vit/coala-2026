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

    values.push_back(0);
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

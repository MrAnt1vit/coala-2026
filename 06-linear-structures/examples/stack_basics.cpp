#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> values;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        values.push(value);
    }

    while (!values.empty()) {
        cout << values.top() << ' ';
        values.pop();
    }
    cout << '\n';
}

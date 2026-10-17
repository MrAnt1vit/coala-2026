#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<long long> values;
    string token;

    while (cin >> token) {
        if (token[0] >= '0' && token[0] <= '9') {
            values.push(token[0] - '0');
            continue;
        }

        long long right = values.top();
        values.pop();
        long long left = values.top();
        values.pop();

        if (token == "+") {
            values.push(left + right);
        } else if (token == "-") {
            values.push(left - right);
        } else {
            values.push(left * right);
        }
    }

    cout << values.top() << '\n';
}

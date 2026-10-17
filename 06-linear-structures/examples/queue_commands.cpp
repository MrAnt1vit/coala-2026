#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<int> values;
    string command;

    while (cin >> command && command != "exit") {
        if (command == "push") {
            int value;
            cin >> value;
            values.push(value);
            cout << "ok\n";
        } else if (command == "pop") {
            cout << values.front() << '\n';
            values.pop();
        } else if (command == "front") {
            cout << values.front() << '\n';
        } else if (command == "size") {
            cout << values.size() << '\n';
        } else if (command == "clear") {
            while (!values.empty()) {
                values.pop();
            }
            cout << "ok\n";
        }
    }

    cout << "bye\n";
}

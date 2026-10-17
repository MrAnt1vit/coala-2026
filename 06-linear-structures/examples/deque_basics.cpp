#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int queries;
    cin >> queries;

    deque<int> values;
    while (queries--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int value;
            cin >> value;
            values.push_front(value);
        } else if (command == "push_back") {
            int value;
            cin >> value;
            values.push_back(value);
        } else if (command == "pop_front") {
            cout << values.front() << '\n';
            values.pop_front();
        } else if (command == "pop_back") {
            cout << values.back() << '\n';
            values.pop_back();
        } else if (command == "front") {
            cout << values.front() << '\n';
        } else if (command == "back") {
            cout << values.back() << '\n';
        } else if (command == "size") {
            cout << values.size() << '\n';
        }
    }
}

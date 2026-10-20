#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int data[100];
    int size = 0;
    string command;

    while (cin >> command && command != "exit") {
        if (command == "push") {
            int value;
            cin >> value;
            data[size] = value;
            ++size;
            cout << "ok\n";
        } else if (command == "pop") {
            --size;
            cout << data[size] << '\n';
        } else if (command == "back") {
            cout << data[size - 1] << '\n';
        } else if (command == "size") {
            cout << size << '\n';
        } else if (command == "clear") {
            size = 0;
            cout << "ok\n";
        }
    }

    cout << "bye\n";
}

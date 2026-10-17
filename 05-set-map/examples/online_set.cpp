#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int queries;
    cin >> queries;

    set<int> values;
    while (queries--) {
        string command;
        cin >> command;

        if (command == "ADD") {
            int x;
            cin >> x;
            values.insert(x);
        } else if (command == "PRESENT") {
            int x;
            cin >> x;
            cout << (values.find(x) != values.end() ? "YES" : "NO") << '\n';
        } else if (command == "COUNT") {
            cout << values.size() << '\n';
        }
    }
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        string source;
        cin >> source;

        string remaining;
        for (char current : source) {
            if (!remaining.empty() && current == 'B') {
                remaining.pop_back();
            } else {
                remaining.push_back(current);
            }
        }

        cout << remaining.size() << '\n';
    }
}

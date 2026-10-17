#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation.find('+') != string::npos) {
            x++;
        } else {
            x--;
        }
    }

    cout << x << '\n';
}

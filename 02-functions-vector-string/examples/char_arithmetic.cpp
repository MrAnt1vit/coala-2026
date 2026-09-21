#include <iostream>

using namespace std;

int main() {
    char digit;
    cin >> digit;

    if ('0' <= digit && digit <= '9') {
        cout << digit - '0' << '\n';
    }
}

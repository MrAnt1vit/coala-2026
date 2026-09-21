#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << '\n';
    } else {
        cout << 1 + (n - 3) / 2 << '\n';
    }
}

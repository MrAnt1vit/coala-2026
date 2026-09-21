#include <iostream>

using namespace std;

int main() {
    const int MAX_N = 100;
    int a[MAX_N];
    int n;
    cin >> n;

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 || a[i] > maximum) {
            maximum = a[i];
        }
    }

    cout << maximum << '\n';
}

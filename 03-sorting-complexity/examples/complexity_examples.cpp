#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // O(n)
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // O(log n)
    int halvings = 0;
    for (int x = n; x > 0; x /= 2) {
        halvings++;
    }

    // O(sqrt(n)): проверяем возможные делители только до корня.
    vector<int> divisors;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n) {
                divisors.push_back(n / d);
            }
        }
    }

    cout << "sum = " << sum << '\n';
    cout << "halvings = " << halvings << '\n';
    cout << "divisors found = " << divisors.size() << '\n';
}

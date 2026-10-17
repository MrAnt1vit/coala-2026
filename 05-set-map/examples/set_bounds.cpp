#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> values = {2, 4, 7, 10};
    int x = 5;

    auto at_least = values.lower_bound(x);
    if (at_least != values.end()) {
        cout << "first >= " << x << ": " << *at_least << '\n';
    }

    auto strictly_greater = values.upper_bound(7);
    if (strictly_greater != values.end()) {
        cout << "first > 7: " << *strictly_greater << '\n';
    }
}

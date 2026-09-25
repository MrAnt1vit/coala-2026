#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool by_absolute_value(int x, int y) {
    if (abs(x) != abs(y)) {
        return abs(x) < abs(y);
    }
    return x < y;
}

bool before_for_minimum_number(const string& a, const string& b) {
    return a + b < b + a;
}

int main() {
    vector<int> numbers = {-5, 2, -1, 3};
    sort(numbers.begin(), numbers.end(), by_absolute_value);

    for (int value : numbers) {
        cout << value << ' ';
    }
    cout << '\n';

    vector<string> parts = {"9", "34", "3"};
    sort(parts.begin(), parts.end(), before_for_minimum_number);

    for (const string& part : parts) {
        cout << part;
    }
    cout << '\n';
}

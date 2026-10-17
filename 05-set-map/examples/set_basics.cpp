#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> values = {8, 3, 8, 1};
    values.insert(5);
    values.erase(3);

    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';

    int wanted = 5;
    if (values.find(wanted) != values.end()) {
        cout << wanted << " is present\n";
    }
    cout << "different values: " << values.size() << '\n';
}

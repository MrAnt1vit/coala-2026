#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> values = {1, 1, 3, 5};
    cout << "ones: " << values.count(1) << '\n';

    auto one = values.find(1);
    if (one != values.end()) {
        values.erase(one); // удаляем ровно одно вхождение
    }

    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

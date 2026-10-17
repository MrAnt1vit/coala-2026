#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<int, string> names = {
        {3, "Cora"},
        {1, "Ada"},
        {2, "Bjarne"},
    };

    for (const auto& [id, name] : names) {
        cout << id << ": " << name << '\n';
    }
}

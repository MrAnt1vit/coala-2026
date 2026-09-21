#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cin >> text;

    if (text.size() >= 3) {
        cout << text[2] << '\n';
    }
    if (text.size() >= 2) {
        cout << text[text.size() - 2] << '\n';
    }

    for (size_t i = 0; i < text.size(); i += 2) {
        cout << text[i];
    }
    cout << '\n';

    for (int i = static_cast<int>(text.size()) - 1; i >= 0; i--) {
        cout << text[i];
    }
    cout << '\n';
}

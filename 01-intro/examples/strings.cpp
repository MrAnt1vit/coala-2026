#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    if (!text.empty()) {
        cout << text[0] << '\n';
    }

    cout << text + "!" << '\n';
}

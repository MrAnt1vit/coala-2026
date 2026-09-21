#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    if (!text.empty()) {
        cout << text.front() << ' ' << text.back() << '\n';
    }

    size_t pos = text.find("abc");
    if (pos != string::npos) {
        cout << text.substr(pos, 3) << '\n';
    }
}

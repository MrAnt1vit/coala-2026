#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    string result;
    for (char symbol : input) {
        if (!result.empty() && result.back() == symbol) {
            result.pop_back();
        } else {
            result.push_back(symbol);
        }
    }

    cout << result << '\n';
}

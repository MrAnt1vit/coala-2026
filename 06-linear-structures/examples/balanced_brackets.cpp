#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool matches(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    string brackets;
    cin >> brackets;

    stack<char> opened;
    for (char bracket : brackets) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            opened.push(bracket);
        } else {
            if (opened.empty() || !matches(opened.top(), bracket)) {
                cout << "no\n";
                return 0;
            }
            opened.pop();
        }
    }

    cout << (opened.empty() ? "yes\n" : "no\n");
}

#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int students;
    cin >> students;

    deque<string> papers;
    for (int i = 0; i < students; i++) {
        string surname;
        string side;
        cin >> surname >> side;

        if (side == "top") {
            papers.push_front(surname);
        } else {
            papers.push_back(surname);
        }
    }

    int queries;
    cin >> queries;
    while (queries--) {
        int position;
        cin >> position;
        cout << papers[position - 1] << '\n';
    }
}

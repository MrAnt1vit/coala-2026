#include <deque>
#include <iostream>

using namespace std;

int main() {
    int queries;
    cin >> queries;

    deque<int> first_half;
    deque<int> second_half;

    while (queries--) {
        char command;
        cin >> command;

        if (command == '+') {
            int goblin;
            cin >> goblin;
            second_half.push_back(goblin);
            if (second_half.size() > first_half.size()) {
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }
        } else if (command == '*') {
            int goblin;
            cin >> goblin;
            if (first_half.size() > second_half.size()) {
                second_half.push_front(goblin);
            } else {
                first_half.push_back(goblin);
            }
        } else {
            cout << first_half.front() << '\n';
            first_half.pop_front();
            if (first_half.size() < second_half.size()) {
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }
        }
    }
}

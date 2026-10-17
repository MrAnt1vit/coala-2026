#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> first;
    deque<int> second;

    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        first.push_back(card);
    }
    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        second.push_back(card);
    }

    const int limit = 1'000'000;
    int moves = 0;
    while (!first.empty() && !second.empty() && moves < limit) {
        int first_card = first.front();
        int second_card = second.front();
        first.pop_front();
        second.pop_front();

        bool first_wins =
            (first_card == 0 && second_card == 9) ||
            (first_card > second_card && !(first_card == 9 && second_card == 0));

        if (first_wins) {
            first.push_back(first_card);
            first.push_back(second_card);
        } else {
            second.push_back(first_card);
            second.push_back(second_card);
        }
        moves++;
    }

    if (moves == limit) {
        cout << "botva\n";
    } else if (second.empty()) {
        cout << "first " << moves << '\n';
    } else {
        cout << "second " << moves << '\n';
    }
}

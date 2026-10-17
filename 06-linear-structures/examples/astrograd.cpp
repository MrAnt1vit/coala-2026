#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int events;
    cin >> events;

    deque<int> line;
    vector<int> position(100001);
    int first_position = 0;
    int next_position = 0;

    while (events--) {
        int type;
        cin >> type;

        if (type == 1) {
            int id;
            cin >> id;
            position[id] = next_position++;
            line.push_back(id);
        } else if (type == 2) {
            line.pop_front();
            first_position++;
        } else if (type == 3) {
            line.pop_back();
            next_position--;
        } else if (type == 4) {
            int id;
            cin >> id;
            cout << position[id] - first_position << '\n';
        } else {
            cout << line.front() << '\n';
        }
    }
}

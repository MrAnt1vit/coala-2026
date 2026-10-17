#include <array>
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class CircularQueue {
private:
    static constexpr int capacity = 101;
    array<int, capacity> data{};
    int head = 0;
    int tail = 0;
    int count = 0;

public:
    void push(int value) {
        data[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    int front() const {
        return data[head];
    }

    void pop() {
        head = (head + 1) % capacity;
        count--;
    }

    int size() const {
        return count;
    }

    void clear() {
        head = 0;
        tail = 0;
        count = 0;
    }
};

int main() {
    CircularQueue values;
    string command;

    while (cin >> command && command != "exit") {
        if (command == "push") {
            int value;
            cin >> value;
            values.push(value);
            cout << "ok\n";
        } else if (command == "pop") {
            cout << values.front() << '\n';
            values.pop();
        } else if (command == "front") {
            cout << values.front() << '\n';
        } else if (command == "size") {
            cout << values.size() << '\n';
        } else if (command == "clear") {
            values.clear();
            cout << "ok\n";
        }
    }

    cout << "bye\n";
}

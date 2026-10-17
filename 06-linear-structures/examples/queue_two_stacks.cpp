#include <cstddef>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class QueueOnStacks {
private:
    stack<int> input;
    stack<int> output;

    void prepare_front() {
        if (!output.empty()) {
            return;
        }
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    void push(int value) {
        input.push(value);
    }

    int front() {
        prepare_front();
        return output.top();
    }

    void pop() {
        prepare_front();
        output.pop();
    }

    size_t size() const {
        return input.size() + output.size();
    }

    void clear() {
        input = stack<int>();
        output = stack<int>();
    }
};

int main() {
    QueueOnStacks values;
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

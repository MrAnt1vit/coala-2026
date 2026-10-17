#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int previous;
    cin >> previous;

    int increasing = 1;
    int decreasing = 1;
    int answer = 1;

    int current;
    while (cin >> current && current != 0) {
        increasing = current > previous ? increasing + 1 : 1;
        decreasing = current < previous ? decreasing + 1 : 1;
        answer = max({answer, increasing, decreasing});
        previous = current;
    }

    cout << answer << '\n';
}

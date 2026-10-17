#include <iostream>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long prefix_maximum;
    cin >> prefix_maximum;
    int prefix_position = 1;

    long long best_difference = numeric_limits<long long>::max();
    int answer_i = 1;
    int answer_j = 2;

    for (int j = 2; j <= n; j++) {
        long long value;
        cin >> value;

        long long difference = value - prefix_maximum;
        if (difference < best_difference) {
            best_difference = difference;
            answer_i = prefix_position;
            answer_j = j;
        }

        if (value > prefix_maximum) {
            prefix_maximum = value;
            prefix_position = j;
        }
    }

    cout << answer_i << ' ' << answer_j << '\n';
}

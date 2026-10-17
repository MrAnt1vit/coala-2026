#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> values(n);
    for (long long& value : values) {
        cin >> value;
    }

    long long x;
    cin >> x;

    long long answer = values[0];
    for (long long value : values) {
        long long distance = abs(value - x);
        long long best_distance = abs(answer - x);
        if (distance < best_distance || (distance == best_distance && value < answer)) {
            answer = value;
        }
    }

    cout << answer << '\n';
}

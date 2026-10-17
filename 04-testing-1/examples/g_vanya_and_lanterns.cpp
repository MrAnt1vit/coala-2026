#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long street_length;
    cin >> n >> street_length;

    vector<long long> lanterns(n);
    for (long long& position : lanterns) {
        cin >> position;
    }
    sort(lanterns.begin(), lanterns.end());

    double answer = max(
        static_cast<double>(lanterns.front()),
        static_cast<double>(street_length - lanterns.back())
    );
    for (int i = 1; i < n; i++) {
        answer = max(answer, (lanterns[i] - lanterns[i - 1]) / 2.0);
    }

    cout << fixed << setprecision(10) << answer << '\n';
}

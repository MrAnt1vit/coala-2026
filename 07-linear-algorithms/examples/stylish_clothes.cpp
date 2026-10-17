#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int shirt_count;
    cin >> shirt_count;
    vector<long long> shirts(shirt_count);
    for (long long& color : shirts) {
        cin >> color;
    }

    int trousers_count;
    cin >> trousers_count;
    vector<long long> trousers(trousers_count);
    for (long long& color : trousers) {
        cin >> color;
    }

    int shirt = 0;
    int trouser = 0;
    long long best_difference = numeric_limits<long long>::max();
    long long best_shirt = shirts[0];
    long long best_trousers = trousers[0];

    while (shirt < shirt_count && trouser < trousers_count) {
        const long long difference = llabs(shirts[shirt] - trousers[trouser]);
        if (difference < best_difference) {
            best_difference = difference;
            best_shirt = shirts[shirt];
            best_trousers = trousers[trouser];
        }

        if (shirts[shirt] < trousers[trouser]) {
            ++shirt;
        } else {
            ++trouser;
        }
    }

    cout << best_shirt << ' ' << best_trousers << '\n';
}

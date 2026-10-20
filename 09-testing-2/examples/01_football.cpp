#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> goals;
    string winner;
    int best_score = 0;

    for (int i = 0; i < n; ++i) {
        string team;
        cin >> team;
        const int score = ++goals[team];
        if (score > best_score) {
            best_score = score;
            winner = team;
        }
    }

    cout << winner << '\n';
}

#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, people;
    cin >> n >> people;
    queue<pair<long long, int>> q;
    unordered_set<long long> occupied;
    occupied.reserve(2 * (static_cast<size_t>(n) + people) + 10);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        q.push({x, 0});
        occupied.insert(x);
    }

    vector<long long> answer;
    answer.reserve(people);
    long long sum = 0;
    while (answer.size() < static_cast<size_t>(people)) {
        auto [x, dist] = q.front();
        q.pop();
        for (long long next : {x - 1, x + 1}) {
            if (occupied.insert(next).second) {
                answer.push_back(next);
                sum += dist + 1;
                q.push({next, dist + 1});
                if (answer.size() == static_cast<size_t>(people)) break;
            }
        }
    }
    cout << sum << '\n';
    for (size_t i = 0; i < answer.size(); ++i) {
        if (i) cout << ' ';
        cout << answer[i];
    }
    cout << '\n';
}

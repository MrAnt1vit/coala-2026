#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long max_difference;
    cin >> n >> max_difference;

    vector<pair<long long, long long>> friends(n);
    for (auto& [money, friendship] : friends) {
        cin >> money >> friendship;
    }
    sort(friends.begin(), friends.end());

    int left = 0;
    long long window_friendship = 0;
    long long answer = 0;

    for (int right = 0; right < n; ++right) {
        window_friendship += friends[right].second;
        while (friends[right].first - friends[left].first >= max_difference) {
            window_friendship -= friends[left].second;
            ++left;
        }
        answer = max(answer, window_friendship);
    }

    cout << answer << '\n';
}

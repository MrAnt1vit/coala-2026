#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> skill(n);
    for (long long& value : skill) {
        cin >> value;
    }

    sort(skill.begin(), skill.end());

    int answer = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        while (skill[right] - skill[left] > 5) {
            ++left;
        }
        answer = max(answer, right - left + 1);
    }

    cout << answer << '\n';
}

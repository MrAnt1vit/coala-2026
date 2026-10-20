#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<string> first_words;
    set<string> second_words;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        first_words.insert(word);
    }
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        second_words.insert(word);
    }

    int common = 0;
    for (const string& word : first_words) {
        common += second_words.count(word);
    }

    const int only_first = n - common;
    const int only_second = m - common;
    const bool first_wins =
        only_first > only_second ||
        (only_first == only_second && common % 2 == 1);

    cout << (first_wins ? "YES" : "NO") << '\n';
}

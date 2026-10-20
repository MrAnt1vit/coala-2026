#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> reachable(n, vector<int>(n));
    for (vector<int>& row : reachable) {
        for (int& value : row) {
            cin >> value;
        }
    }

    for (int middle = 0; middle < n; ++middle) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                reachable[from][to] |=
                    reachable[from][middle] && reachable[middle][to];
            }
        }
    }

    for (const vector<int>& row : reachable) {
        for (int column = 0; column < n; ++column) {
            cout << row[column] << (column + 1 == n ? '\n' : ' ');
        }
    }
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int edge = 0; edge < m; ++edge) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    for (const vector<int>& row : matrix) {
        for (int column = 0; column < n; ++column) {
            cout << row[column] << (column + 1 == n ? '\n' : ' ');
        }
    }
}

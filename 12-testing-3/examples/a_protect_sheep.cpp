#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    cin >> rows >> cols;
    vector<string> field(rows);
    for (string& row : field) cin >> row;

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (field[r][c] != 'W') continue;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (0 <= nr && nr < rows && 0 <= nc && nc < cols &&
                    field[nr][nc] == 'S') {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    for (string& row : field) {
        for (char& cell : row) if (cell == '.') cell = 'D';
        cout << row << '\n';
    }
}

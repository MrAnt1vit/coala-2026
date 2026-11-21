#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> tree_max;    // максимум на отрезке вершины
vector<int> tree_index;  // индекс выбранного максимума

void build(int v, int l, int r, vector<int>& a) {
    if (r - l == 1) {
        tree_max[v] = a[l];
        tree_index[v] = l;
        return;
    }

    int m = (l + r) / 2;
    build(2 * v, l, m, a);
    build(2 * v + 1, m, r, a);

    if (tree_max[2 * v] > tree_max[2 * v + 1]) {
        tree_max[v] = tree_max[2 * v];
        tree_index[v] = tree_index[2 * v];
    } else {
        tree_max[v] = tree_max[2 * v + 1];
        tree_index[v] = tree_index[2 * v + 1];
    }
}

// Возвращает пару: максимальное значение и его индекс.
pair<int, int> get(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return {tree_max[v], tree_index[v]};
    if (r <= ql || qr <= l) return {0, -1}; // числа в задаче положительны

    int m = (l + r) / 2;
    pair<int, int> left = get(2 * v, l, m, ql, qr);
    pair<int, int> right = get(2 * v + 1, m, r, ql, qr);
    if (left.first > right.first) return left;
    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& value : a) cin >> value;

    tree_max.resize(4 * n + 4);
    tree_index.resize(4 * n + 4);
    build(1, 0, n, a);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int left, right;
        cin >> left >> right;
        --left;
        --right;
        if (i) cout << ' ';
        cout << get(1, 0, n, left, right + 1).second + 1;
    }
    cout << '\n';
}

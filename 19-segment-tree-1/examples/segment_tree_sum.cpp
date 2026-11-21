#include <iostream>
#include <vector>

using namespace std;

vector<long long> a;
vector<long long> tree;

// Вершина v отвечает за полуинтервал [l, r).
void build(int v, int l, int r) {
    if (r - l == 1) {
        tree[v] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

// Сумма элементов из пересечения [l, r) и [ql, qr).
long long get(int v, int l, int r, int ql, int qr) {
    if (r <= ql || qr <= l) return 0;
    if (ql <= l && r <= qr) return tree[v];

    int m = (l + r) / 2;
    return get(2 * v, l, m, ql, qr)
         + get(2 * v + 1, m, r, ql, qr);
}

// Присвоить a[index] новое значение и пересчитать его предков.
void update(int v, int l, int r, int index, long long value) {
    if (r - l == 1) {
        tree[v] = value;
        return;
    }

    int m = (l + r) / 2;
    if (index < m) update(2 * v, l, m, index, value);
    else update(2 * v + 1, m, r, index, value);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    a.assign(n, 0);                // по условию массив изначально нулевой
    tree.resize(4 * n + 4);
    build(1, 0, n);

    while (q--) {
        char type;
        cin >> type;
        if (type == 'A') {
            int index;
            long long value;
            cin >> index >> value;
            update(1, 0, n, index - 1, value); // из 1-индексации в 0-индексацию
        } else if (type == 'Q') {
            int left, right;
            cin >> left >> right;
            cout << get(1, 0, n, left - 1, right) << '\n';
        }
    }
}

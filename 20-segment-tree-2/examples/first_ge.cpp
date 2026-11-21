#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

void build(int v, int l, int r, const vector<int>& a) {
    if (r - l == 1) {
        tree[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, a);
    build(2 * v + 1, mid, r, a);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

void update(int v, int l, int r, int index, int value) {
    if (r - l == 1) {
        tree[v] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (index < mid) update(2 * v, l, mid, index, value);
    else update(2 * v + 1, mid, r, index, value);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

// Вся вершина лежит в запросе, и её максимум не меньше x.
int find_first(int v, int l, int r, int x) {
    if (r - l == 1) return l;
    int mid = (l + r) / 2;
    if (tree[2 * v] >= x) return find_first(2 * v, l, mid, x);
    return find_first(2 * v + 1, mid, r, x);
}

// Первый индекс в [ql, qr), где значение не меньше x; -1, если его нет.
int get(int v, int l, int r, int ql, int qr, int x) {
    if (r <= ql || qr <= l) return -1;
    if (ql <= l && r <= qr) {
        if (tree[v] < x) return -1;
        return find_first(v, l, r, x);
    }
    int mid = (l + r) / 2;
    int left = get(2 * v, l, mid, ql, qr, x);
    if (left != -1) return left;
    return get(2 * v + 1, mid, r, ql, qr, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& value : a) cin >> value;
    tree.resize(4 * n + 4);
    build(1, 0, n, a);

    while (m--) {
        int type, i, x;
        cin >> type >> i >> x;
        if (type == 0) {
            update(1, 0, n, i - 1, x);
        } else {
            int index = get(1, 0, n, i - 1, n, x);
            cout << (index == -1 ? -1 : index + 1) << '\n';
        }
    }
}

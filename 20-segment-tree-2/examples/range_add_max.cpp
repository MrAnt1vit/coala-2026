#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> tree;     // максимум без ещё не применённого pending[v]
vector<long long> pending;  // сколько прибавить вершине при следующем обращении

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

void push_node(int v, int l, int r) {
    tree[v] += pending[v];
    if (r - l != 1) {
        pending[2 * v] += pending[v];
        pending[2 * v + 1] += pending[v];
    }
    pending[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, long long add) {
    push_node(v, l, r);
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        pending[v] += add;
        push_node(v, l, r);  // родитель затем увидит актуальный максимум
        return;
    }
    int mid = (l + r) / 2;
    update(2 * v, l, mid, ql, qr, add);
    update(2 * v + 1, mid, r, ql, qr, add);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

long long get(int v, int l, int r, int ql, int qr) {
    push_node(v, l, r);
    if (r <= ql || qr <= l) return -1;  // числа задачи неотрицательны
    if (ql <= l && r <= qr) return tree[v];
    int mid = (l + r) / 2;
    return max(get(2 * v, l, mid, ql, qr),
               get(2 * v + 1, mid, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& value : a) cin >> value;
    tree.resize(4 * n + 4);
    pending.resize(4 * n + 4);
    build(1, 0, n, a);

    int m;
    cin >> m;
    while (m--) {
        char type;
        int l, r;
        cin >> type >> l >> r;
        if (type == 'm') {
            cout << get(1, 0, n, l - 1, r) << '\n';
        } else {  // 'a'
            long long add;
            cin >> add;
            update(1, 0, n, l - 1, r, add);
        }
    }
}

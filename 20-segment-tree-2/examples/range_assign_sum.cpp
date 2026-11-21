#include <iostream>
#include <vector>

using namespace std;

// Только здесь, в третьей задаче, собираем поля вершины в struct.
struct Node {
    long long sum = 0;
    long long push = -1;  // -1: отложенного присваивания нет
    int l = 0;
    int r = 0;
};

vector<Node> tree;

void build(int v, int l, int r) {
    tree[v].l = l;
    tree[v].r = r;
    tree[v].push = -1;
    if (r - l == 1) {
        tree[v].sum = 0;  // по условию начальный массив нулевой
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid, r);
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

void push_node(int v) {
    if (tree[v].push == -1) return;
    tree[v].sum = (tree[v].r - tree[v].l) * tree[v].push;
    if (tree[v].r - tree[v].l != 1) {
        tree[2 * v].push = tree[v].push;
        tree[2 * v + 1].push = tree[v].push;
    }
    tree[v].push = -1;
}

void update(int v, int ql, int qr, long long value) {
    push_node(v);
    if (tree[v].r <= ql || qr <= tree[v].l) return;
    if (ql <= tree[v].l && tree[v].r <= qr) {
        tree[v].push = value;
        push_node(v);
        return;
    }
    update(2 * v, ql, qr, value);
    update(2 * v + 1, ql, qr, value);
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

long long get(int v, int ql, int qr) {
    push_node(v);
    if (tree[v].r <= ql || qr <= tree[v].l) return 0;
    if (ql <= tree[v].l && tree[v].r <= qr) return tree[v].sum;
    return get(2 * v, ql, qr) + get(2 * v + 1, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    tree.resize(4 * n + 4);
    build(1, 0, n);

    while (k--) {
        char type;
        int l, r;
        cin >> type >> l >> r;
        if (type == 'Q') {
            cout << get(1, l - 1, r) << '\n';
        } else {  // 'A'
            long long value;
            cin >> value;
            update(1, l - 1, r, value);
        }
    }
}

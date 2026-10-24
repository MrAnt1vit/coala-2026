#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components;

    explicit DSU(int n) : parent(n + 1), size(n + 1, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (parent[v] != v) parent[v] = find(parent[v]);
        return parent[v];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        --components;
    }
};

struct Bridge { int u, v, height; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int islands, bridges;
    cin >> islands >> bridges;
    vector<Bridge> edges(bridges);
    for (Bridge& e : edges) cin >> e.u >> e.v >> e.height;
    sort(edges.begin(), edges.end(), [](const Bridge& a, const Bridge& b) {
        return a.height > b.height;
    });

    DSU dsu(islands);
    for (const Bridge& e : edges) {
        dsu.unite(e.u, e.v);
        if (dsu.components == 1) {
            cout << e.height << '\n';
            break;
        }
    }
}

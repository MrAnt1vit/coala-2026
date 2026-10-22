#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<int>>& children, vector<int>& tin,
         vector<int>& tout, int& timer) {
    tin[v] = timer++;
    for (int child : children[v]) dfs(child, children, tin, tout, timer);
    tout[v] = timer++;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> children(n);
    int root = -1;
    for (int v = 0; v < n; ++v) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            root = v;
        } else {
            children[parent - 1].push_back(v);
        }
    }

    vector<int> tin(n), tout(n);
    int timer = 0;
    dfs(root, children, tin, tout, timer);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << (tin[a] < tin[b] && tout[b] < tout[a]) << '\n';
    }
}

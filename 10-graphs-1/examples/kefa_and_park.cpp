#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, maximum_cats;
    cin >> n >> maximum_cats;
    vector<int> has_cat(n);
    for (int& value : has_cat) {
        cin >> value;
    }

    vector<vector<int>> tree(n);
    for (int edge = 0; edge < n - 1; ++edge) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<tuple<int, int, int>> stack;
    stack.push_back({0, -1, has_cat[0]});
    int answer = 0;

    while (!stack.empty()) {
        const auto [vertex, parent, consecutive_cats] = stack.back();
        stack.pop_back();

        if (consecutive_cats > maximum_cats) {
            continue;
        }

        bool is_leaf = vertex != 0 && tree[vertex].size() == 1;
        if (is_leaf) {
            ++answer;
            continue;
        }

        for (int to : tree[vertex]) {
            if (to == parent) {
                continue;
            }
            const int next_cats = has_cat[to] ? consecutive_cats + 1 : 0;
            stack.push_back({to, vertex, next_cats});
        }
    }

    cout << answer << '\n';
}

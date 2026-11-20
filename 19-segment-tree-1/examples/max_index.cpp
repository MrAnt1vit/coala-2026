#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Node {
    long long maximum;
    int index;
};

Node combine(Node left, Node right) {
    if (left.maximum != right.maximum) {
        return left.maximum > right.maximum ? left : right;
    }
    if (left.index == -1) return right;
    if (right.index == -1) return left;
    return left.index < right.index ? left : right;
}

class MaxIndexTree {
public:
    explicit MaxIndexTree(const vector<long long>& values)
        : size_(static_cast<int>(values.size())), tree_(4 * size_ + 4) {
        build(1, 0, size_, values);
    }

    Node get(int left, int right) const {
        return get(1, 0, size_, left, right);
    }

private:
    int size_;
    vector<Node> tree_;

    void build(int vertex, int left, int right, const vector<long long>& values) {
        if (right - left == 1) {
            tree_[vertex] = {values[left], left};
            return;
        }
        int middle = left + (right - left) / 2;
        build(vertex * 2, left, middle, values);
        build(vertex * 2 + 1, middle, right, values);
        tree_[vertex] = combine(tree_[vertex * 2], tree_[vertex * 2 + 1]);
    }

    Node get(int vertex, int left, int right,
             int query_left, int query_right) const {
        if (query_right <= left || right <= query_left) {
            return {numeric_limits<long long>::lowest(), -1};
        }
        if (query_left <= left && right <= query_right) return tree_[vertex];
        int middle = left + (right - left) / 2;
        return combine(get(vertex * 2, left, middle, query_left, query_right),
                       get(vertex * 2 + 1, middle, right, query_left, query_right));
    }
};

// Contest task 2: one-based inclusive bounds in input, one-based indices in output.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> values(n);
    for (auto& value : values) cin >> value;
    MaxIndexTree tree(values);

    int query_count;
    cin >> query_count;
    for (int i = 0; i < query_count; ++i) {
        int left, right;
        cin >> left >> right;
        if (i) cout << ' ';
        cout << tree.get(left - 1, right).index + 1;
    }
    cout << '\n';
}

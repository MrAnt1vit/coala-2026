#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// All intervals in the tree are half-open: [left, right).
class SegmentTreeSum {
public:
    explicit SegmentTreeSum(const vector<long long>& values)
        : size_(static_cast<int>(values.size())), tree_(4 * size_ + 4, 0) {
        assert(size_ > 0);
        build(1, 0, size_, values);
    }

    long long sum(int left, int right) const {
        assert(0 <= left && left <= right && right <= size_);
        return sum(1, 0, size_, left, right);
    }

    void set_value(int index, long long value) {
        assert(0 <= index && index < size_);
        set_value(1, 0, size_, index, value);
    }

private:
    int size_;
    vector<long long> tree_;

    void build(int vertex, int left, int right, const vector<long long>& values) {
        if (right - left == 1) {
            tree_[vertex] = values[left];
            return;
        }
        int middle = left + (right - left) / 2;
        build(vertex * 2, left, middle, values);
        build(vertex * 2 + 1, middle, right, values);
        tree_[vertex] = tree_[vertex * 2] + tree_[vertex * 2 + 1];
    }

    long long sum(int vertex, int left, int right,
                  int query_left, int query_right) const {
        if (query_right <= left || right <= query_left) return 0;
        if (query_left <= left && right <= query_right) return tree_[vertex];
        int middle = left + (right - left) / 2;
        return sum(vertex * 2, left, middle, query_left, query_right) +
               sum(vertex * 2 + 1, middle, right, query_left, query_right);
    }

    void set_value(int vertex, int left, int right,
                   int index, long long value) {
        if (right - left == 1) {
            tree_[vertex] = value;
            return;
        }
        int middle = left + (right - left) / 2;
        if (index < middle) set_value(vertex * 2, left, middle, index, value);
        else set_value(vertex * 2 + 1, middle, right, index, value);
        tree_[vertex] = tree_[vertex * 2] + tree_[vertex * 2 + 1];
    }
};

// Contest task 1: initially all zeros; A i x sets a one-based position,
// Q l r asks for the sum on a one-based inclusive interval.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> values(n, 0);
    SegmentTreeSum tree(values);

    while (q--) {
        char operation;
        cin >> operation;
        if (operation == 'Q') {
            int left, right;
            cin >> left >> right;
            cout << tree.sum(left - 1, right) << '\n';
        } else if (operation == 'A') {
            int index;
            long long value;
            cin >> index >> value;
            tree.set_value(index - 1, value);
        }
    }
}

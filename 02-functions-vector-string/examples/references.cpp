#include <iostream>
#include <vector>

using namespace std;

void add_one(int& x) {
    x++;
}

long long sum(const vector<int>& values) {
    long long result = 0;
    for (int value : values) {
        result += value;
    }
    return result;
}

int main() {
    int x = 4;
    add_one(x);
    cout << x << '\n';
}

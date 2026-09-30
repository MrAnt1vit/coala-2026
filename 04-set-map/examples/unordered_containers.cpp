#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> used = {5, 1, 5, 3};
    cout << "contains 3: " << (used.find(3) != used.end()) << '\n';

    unordered_map<int, int> frequency;
    for (int value : {5, 1, 5, 3, 5}) {
        frequency[value]++;
    }
    cout << "count of 5: " << frequency[5] << '\n';
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int& value : height) {
        cin >> value;
    }

    int maximum_position = 0;
    int minimum_position = 0;
    for (int i = 1; i < n; i++) {
        if (height[i] > height[maximum_position]) {
            maximum_position = i;
        }
        if (height[i] <= height[minimum_position]) {
            minimum_position = i;
        }
    }

    int answer = maximum_position + (n - 1 - minimum_position);
    if (maximum_position > minimum_position) {
        answer--;
    }

    cout << answer << '\n';
}

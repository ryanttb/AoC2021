#include <climits>
#include <iostream>

using namespace std;

constexpr int NO_MEASUREMENT = INT_MAX;

int main() {
    int depth {NO_MEASUREMENT};
    int last_depth {NO_MEASUREMENT};
    int times_incrased {0};

    while (cin >> depth) {
        cout << depth;

        if (last_depth == NO_MEASUREMENT) {
            cout << " (N/A - no previous measurement)";
        } else {
            if (depth == last_depth) {
                cout << " (no change)";
            } else if (depth > last_depth) {
                cout << " (increased)";
                ++times_incrased;
            } else {
                cout << " (decrased)";
            }
        }
        cout << endl;

        last_depth = depth;
    }

    cout << times_incrased << " measurments are larger than the previous measurement" << endl;
    return 0;
}

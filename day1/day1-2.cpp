#include <climits>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

constexpr int NO_MEASUREMENT {INT_MAX};
constexpr int DEFAULT_WINDOW_SIZE {3};

class MeasurementWindow {
public:
    MeasurementWindow() : 
        m_window_size {DEFAULT_WINDOW_SIZE} {
    }
    
    MeasurementWindow(int window_size) : 
        m_window_size {window_size} {
    }

    size_t size() {
        return data.size();
    }

    bool full() {
        return data.size() == m_window_size;
    }

    void push_back(int measurement) {
        if (full()) {
            throw runtime_error("window full");
        }

        data.push_back(measurement);
    }

    int sum() {
        if (!full()) {
            throw runtime_error("sum on non-full window");
        }
        return accumulate(data.begin(), data.end(), 0);
    }

    string str() {
        ostringstream os;
        os << "MW: ";
        for (auto m : data) {
            os << m << ", ";
        }
        return os.str();
    }

private:
    int m_window_size;

    vector<int> data;
};

int main() {
    int depth {NO_MEASUREMENT};
    int last_sum {NO_MEASUREMENT};
    int times_incrased {0};

    vector<MeasurementWindow> measurements;

    while (cin >> depth) {
        cout << "depth: " << depth << endl;

        measurements.push_back(MeasurementWindow());

        // add the new depth to any non-full windows
        auto m = measurements.rbegin();
        for (; m != measurements.rend(); ++m) {
            m->push_back(depth);
            cout << m->str() << endl;
            if (m->full()) {
                break;
            }
        }

        if (m != measurements.rend() && m->full()) {
            int sum = m->sum();
            cout << sum;
            if (last_sum == NO_MEASUREMENT) {
                cout << " (N/A - no previous sum)";
            } else {
                if (sum == last_sum) {
                    cout << " (no change)";
                } else if (sum > last_sum) {
                    cout << " (increased)";
                    ++times_incrased;
                } else {
                    cout << " (decrased)";
                }
            }
            cout << endl;

            last_sum = sum;
        }
    }

    cout << times_incrased << " measurments are larger than the previous measurement" << endl;
    return 0;
}

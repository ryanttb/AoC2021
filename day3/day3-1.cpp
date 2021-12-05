#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int bitlength {0};
    int count {0};

    vector<int> ones;

    string signal;
    while (cin >> signal) {
        cout << signal << endl;

        if (bitlength == 0) {
            bitlength = signal.length();
            ones.resize(bitlength);
        }

        ++count;

        for (int i {0}; i < signal.length(); ++i) {
            char d = signal[i];
            if (d == '1') {
                ones[i] = ones[i] + 1;
            }
        }
    }

    cout << "count: " << count << endl;

    cout << "ones: ";
    for (int i {0}; i < bitlength; ++i) {
        cout << "[" << ones[i] << "]";
    }
    cout << endl;

    ostringstream gamma_str;
    gamma_str << "gamma:\t";

    ostringstream eps_str;
    eps_str << "eps:\t";

    int gamma {0};
    int eps {0};
    for (int i {0}; i < bitlength; ++i) {
        if ((double)ones[i] / count >= 0.5) {
            gamma_str << 1;
            eps_str << 0;
            gamma += pow(2, bitlength - i - 1);
        } else {
            gamma_str << 0;
            eps_str << 1;
            eps += pow(2, bitlength - i - 1);
        }
    }
    cout << gamma_str.str() << " = " << gamma << endl;
    cout << eps_str.str() << " = " << eps << endl;
    cout << "power: " << gamma * eps << endl;

    return 0;
}

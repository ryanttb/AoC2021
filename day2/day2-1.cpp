#include <climits>
#include <iostream>

using namespace std;

constexpr char AF {'f'}; 
constexpr char AD {'d'};
constexpr char AU {'u'};

struct Command {
    bool get() {
        string a;
        cin >> a;

        if (!cin) {
            cerr << "failed to read action" << endl;
            return false;
        }

        switch (a[0]) {
        case AF:
        case AD:
        case AU:
            action = a[0];
            break;

        default:
            cerr << "read unknown action" << endl;
            return false;
        }

        int m;
        cin >> m;

        if (!cin) {
            cerr << "failed to read magnitude" << endl;
            return false;
        }

        magnitude = m;
        return true;
    }

    char action;
    int magnitude;
};

int main() {
    Command c;

    int pos {0};
    int depth {0};

    while (c.get()) {
        cout << c.action << " " << c.magnitude << endl;

        switch (c.action) {
        case AF:
            pos += c.magnitude;
            break;

        case AD:
            depth += c.magnitude;
            break;

        case AU:
            depth -= c.magnitude;
            break;

        default:
            cout << "unknown action" << endl;
            break;
        }
    }

    cout << "pos: " << pos << ", depth: " << depth << endl;
    cout << "p*d: " << pos * depth << endl;

    return 0;
}

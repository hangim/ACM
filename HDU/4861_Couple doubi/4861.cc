#include <iostream>

using namespace std;

int main() {
    int k, p;
    while (cin >> k >> p) {
        if (k / (p-1) % 2 == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


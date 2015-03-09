#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        int total = 0;
        int n;
        cin >> n;
        for (int i = 0; i != n; ++i) {
            int tmp;
            cin >> tmp;
            total += max(tmp, 0);
        }

        cout << "Case " << k << ": " << total << endl;
    }

    return 0;
}


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;

    while (cin >> n) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int var;
            cin >> var;
            sum += var;
        }

        cin >> m;
        for (int i = 0; i < m; ++i) {
            int var;
            cin >> var;
        }
        
        if (sum == 0)
            cout << "0.00" << endl;
        else if (n == m)
            cout << "inf" << endl;
        else
            cout << setprecision(2) << fixed << 1.0 * sum / (n-m) << endl;
    }

    return 0;
}


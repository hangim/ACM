#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        double p;
        int k1, k2;
        cin >> p >> k1 >> k2;
        if (p < 1e-9) {
            cout << "Case " << cases << ": " << k1 << endl;
            continue;
        }
        if (p > 1 - 1e-9) {
            cout << "Case " << cases << ": " << k2 << endl;
            continue;
        }
        double a = (1 - pow(1- p, k1 - 1)) / p;
        double b = (1 - pow(p, k2 - 1)) / (1 - p);
        double g1 = (a * b * p + a) / (1 - a * b * p * (1 - p));
        double f1 = b * ((1 - p) * g1 + 1);

        cout << "Case " << cases << ": " << setprecision(6)
             << fixed << (1 - p) * g1 + p * f1 + 1 << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

double get_p(int x, int n) {
    return 1.0 - 1.0 * ((x - 1) * (x - 1) + (n - x) * (n - x)) / (n * n);
}

double f(double p, int n) {
    return (1.0 - pow(1.0 - 2.0 * p, n)) / 2.0;
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int X, Y, Z, K;
        cin >> X >> Y >> Z >> K;
        double ans = 0;
        for (int i = 1; i <= X; ++i) {
            double px = get_p(i, X);
            for (int j = 1; j <= Y; ++j) {
                double py = get_p(j, Y);
                for (int k = 1; k <= Z; ++k) {
                    double pz = get_p(k, Z);
                    ans += f(px * py * pz, K);
                }
            }
        }
        cout << "Case " << cases << ": "
             << setprecision(6) << fixed << ans << endl;
    }
    return 0;
}


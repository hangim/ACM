#include <bits/stdc++.h>

using namespace std;

double harmonic_number[5010];

int main() {
    for (int i = 1; i <= 5000; ++i)
        harmonic_number[i] = harmonic_number[i-1] + 1.0 / i;

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            ans += a * (b == 1 ? 1 : harmonic_number[n]);
        }
        cout << "Case " << cases << ": "
             << setprecision(6) << fixed << ans << endl;
    }
    return 0;
}


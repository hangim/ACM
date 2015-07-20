#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int t, d;
        cin >> t >> d;
        cout << "Case " << k << ": " << setprecision(6) << fixed;
        if (t % 2) {
            cout << 0.0 << endl;
            continue;
        }
        double ans = 1;
        while (t) {
            ans *= 1.0 * (t - 1) / (t + 1);
            t -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}


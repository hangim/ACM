#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int n;
        cin >> n;
        double ans = 0;
        for (int i = n - 1; i >= 0; --i)
            ans += 1.0 * n / (n - i);
        cout << "Case " << k << ": "
             << setprecision(6) << fixed << ans << endl;
    }
    return 0;
}


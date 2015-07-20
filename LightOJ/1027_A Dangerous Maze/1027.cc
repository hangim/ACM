#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int n;
        cin >> n;
        int cnt = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x > 0) {
                total += x;
                ++cnt;
            } else {
                total -= x;
            }
        }
        cout << "Case " << k << ": ";
        if (cnt == 0) {
            cout << "inf" << endl;
        } else {
            // cnt / n * E == total / n
            int tmp = gcd(total, cnt);
            cout << total / tmp << "/" << cnt / tmp << endl;
        }
    }
    return 0;
}


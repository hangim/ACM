#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, k = 1;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0, tmp;

        tmp = min(a / 2, b);
        ans += tmp;
        a -= 2 * tmp;
        b -= tmp;

        tmp = min(a / 2, c);
        ans += tmp;
        a -= 2 * tmp;
        c -= tmp;

        ans += a / 3;
        a %= 3;

        ans += (a + b + c + 1) / 2;

        cout << "Case " << k++ << ": " << ans << endl;   
    }
    return 0;
}


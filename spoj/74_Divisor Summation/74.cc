#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0)
                ans += i + n / i;
            if (i * i == n)
                ans -= i;
        }

        if (n == 1)
            ans = 0;
        
        cout << ans << endl;
    }
    return 0;
}


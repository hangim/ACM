#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;
int len, next_val[200010], dp[200010];
char s[200010];

void get_next() {
    int k = next_val[0] = -1, j = 0;
    while (j <= len) {
        if (k == -1 or s[j] == s[k])
            next_val[++j] = ++k;
        else
            k = next_val[k];
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> len >> s;
        get_next();
        int ans = len % MOD;
        dp[0] = 0;
        for (int i = 1; i <= len + 1; ++i) {
            if (next_val[i] != 0)
                dp[i] = (dp[next_val[i]] + 1) % MOD;
            else
                dp[i] = 0;
            ans = (ans + dp[i]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}


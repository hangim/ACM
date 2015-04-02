#include <bits/stdc++.h>

using namespace std;

int A[1010];
int dp[1010];

int main() {
    int n;
    while (cin >> n and n) {
        for (int i = 0; i != n; ++i) {
            cin >> A[i];
            dp[i] = A[i];
        }
        int ans = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != i; ++j)
                if (A[i] > A[j])
                    dp[i] = max(dp[i], dp[j] + A[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }

    return 0;
}


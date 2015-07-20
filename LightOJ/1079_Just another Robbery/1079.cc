#include <bits/stdc++.h>

using namespace std;

int M[110];
double P[110];
double dp[10110];

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        double p;
        int n;
        cin >> p >> n;
        for (int i = 0; i < n; ++i)
            cin >> M[i] >> P[i];
    
        dp[0] = 0;
        for (int i = 1; i <= 10000; ++i)
            dp[i] = 1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = 10000; j >= 0; --j) {
                dp[j+M[i]] = min(1-(1-dp[j])*(1-P[i]), dp[j+M[i]]);
            }
        }
    
        double ans = 0;
        for (int i = 10000; i >= 0; --i) {
            if (dp[i] < p) {
                ans = i;
                break;
            }
        }
        cout << "Case " << cases << ": " << ans << endl;
    }
    return 0;
}


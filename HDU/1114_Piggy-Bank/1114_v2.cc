#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 10;
int dp[10010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int e, t;
        cin >> e >> t;
        for (int i = e + 1; i <= t; ++i)
            dp[i] = INF;
        dp[e] = 0;

        int n;
        cin >> n;
        for (int i = 0; i != n; ++i) {
            int p, w;
            cin >> p >> w;
            for (int j = e + w; j <= t; ++j)
                dp[j] = min(dp[j], dp[j-w] + p);
        }

        if (dp[t] == INF)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is "
                 << dp[t] << "." << endl;
    }

    return 0;
}


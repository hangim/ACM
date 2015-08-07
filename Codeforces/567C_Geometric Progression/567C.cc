#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;

int a[maxn + 10];
map<int, long long> dp[4];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        if (a[i] % k == 0) {
            dp[3][a[i]] += dp[2][a[i] / k];
            dp[2][a[i]] += dp[1][a[i] / k];
        }
        dp[1][a[i]] += 1;
    }

    long long ans = 0;
    for (auto it : dp[3])
        ans += it.second;
    cout << ans << endl;

    return 0;
}


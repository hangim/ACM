#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> dp;

int main() {
    int n;
    while (cin >> n) {
        v.resize(n);
        dp.resize(n);
        for (int i = 0; i != n; ++i)
            cin >> v[i];
        int ans = 0;
        for (int i = 0; i != n; ++i) {
            dp[i] = 1;
            for (int j = 0; j != i; ++j)
                if (v[j] < v[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}


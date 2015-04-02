#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[2001], b[2001];
int dp[2001][2001];

int slove() {
    for (int i = 0; i != n; ++i)
        dp[0][i] = abs(a[0] - b[i]);
    for (int i = 1; i != n; ++i) {
        int tmp = dp[i-1][0];
        for (int j = 0; j != n; ++j) {
            tmp = min(tmp, dp[i-1][j]);
            dp[i][j] = tmp + abs(a[i] - b[j]);
        }
    }
    int ans = dp[n-1][0];
    for (int i = 0; i != n; ++i)
        ans = min(ans, dp[n-1][i]);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    int ans = slove();

    reverse(b, b+n);
    ans = min(ans, slove());

    cout << ans << endl;
    return 0;
}


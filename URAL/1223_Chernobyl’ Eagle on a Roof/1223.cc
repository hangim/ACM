#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[11][1001];

const int INF = 200000000;

int dp(int n, int m) {
    // n eggs
    // m floors
    // cout << "\t" << n << " " << m << endl;
    if (n == 1)
        return m;
    if (m <= 2)
        return m;

    if (memo[n][m] != 0)
        return memo[n][m];

    int ans = INF;
    for (int k = 2; k <= m; k++) {
        // 从 k 层扔
        int tmp = max(dp(n-1, k-1) + 1, dp(n, m-k) + 1);
        ans = min(ans, tmp);
    }

    return memo[n][m] = ans;
}

int main() {

    int n; // n eggs
    int m; // m floors
    memset(memo, 0, sizeof(memo));
    while (cin >> n >> m and n and m) {
        if (n > 10)
            n = 10;
        cout << dp(n, m) << endl;
    }

    return 0;
}


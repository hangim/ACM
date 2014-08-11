#include <iostream>
#include <cstring>

using namespace std;

int n, m;
long long dp[11][1<<11];
bool archive[1<<11];

bool check1(int s) {
    // 只能有偶数个1相连
    int cnt = 0;
    while (s) {
        if (s & 1)
            cnt++;
        else if (cnt & 1)
            return false;
        s >>= 1;
    }

    if (cnt & 1)
        return false;
    else
        return true;
}

bool check2(int s1, int s2) {
    if ((s1|s2) != (1<<m)-1)
        return false;
    return archive[s1 & s2];
}

int main() {
    for (int i = 0; i < 1<<11; i++)
        archive[i] = check1(i);

    while (cin >> n >> m and n + m) {
        memset(dp, 0, sizeof(dp));

        // dp[0]
        for (int i = 0; i < 1<<m; i++) {
            if (archive[i])
                dp[0][i] = 1;
        }

        // dp[1..n-1]
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 1<<m; j++) {
                for (int k = 0; k < 1<<m; k++) {
                    if (check2(j, k)) {
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }

        cout << dp[n-1][(1<<m)-1] << endl;
    }

    return 0;
}


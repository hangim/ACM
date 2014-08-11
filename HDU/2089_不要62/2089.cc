#include <iostream>
#include <cstring>

using namespace std;

int dp[8][10];

void init() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // in order to dp[1][0..9]
    for (int i = 1; i <= 7; i++) { // len
        // num jk...
        for (int j = 0; j <= 9; j++) { // allow leading zero
            if (j == 4)
                continue;
            for (int k = 0; k <= 9; k++) {
                if ((j == 6 and k == 2) or k == 4)
                    continue;
                dp[i][j] += dp[i-1][k];
            }
        }
    }
}

int solve(int n) {
    int num[10];
    memset(num, 0, sizeof(num));

    int len = 0;
    while (n) {
        num[++len] = n % 10;
        n /= 10;
    }

    int ans = 0;
    for (int i = len; i > 0; i--) {
        for (int j = 0; j < num[i]; j++) {
            if (j == 4)
                continue;
            if (num[i+1] == 6 and j == 2)
                continue;
            ans += dp[i][j];
        }

        if (num[i] == 4)
            break;
        if (num[i+1] == 6 and num[i] == 2)
            break;
    }
    
    return ans;
}

int main() {
    init();

    int n, m;
    while (cin >> n >> m and (n + m)) {
        // [0, m] - [0, n)
        int ans = solve(m + 1) - solve(n);

        cout << ans << endl;
    }

    return 0;
}


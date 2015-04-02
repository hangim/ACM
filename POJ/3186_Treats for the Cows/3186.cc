#include <iostream>
#include <algorithm>

using namespace std;

int num[2010];
int dp[2010][2010];

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        dp[i][i] = num[i] * n;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i + k <= n; ++i) {
            int j = i + k;
            dp[i][j] = max(dp[i+1][j] + num[i] * (n - k),
                    dp[i][j-1] + num[j] * (n - k));
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}


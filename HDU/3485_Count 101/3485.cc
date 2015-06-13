#include <bits/stdc++.h>

using namespace std;

int main() {
    int dp[10010] = {0, 2, 4, 7};
    for (int i = 4; i < 10000; ++i)
        dp[i] = (2 * dp[i-1] - (dp[i-2] - dp[i-3])) % 9997;
    int n;
    while (cin >> n and n != -1)
        cout << dp[n] << endl;
    return 0;
}


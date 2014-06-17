#include <iostream>

using namespace std;

int main() {
    int dp[1001] = {0};
    dp[1] = 1;
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; i * j + 1 < 1001; j++) {
            dp[i * j + 1] += dp[i];
            dp[i * j + 1] %= (int)1e9 + 7;
        }
    }

    int index = 1;
    int n;
    while (cin >> n) {
        cout << "Case " << index++ << ": " << dp[n] << endl;
    }

    return 0;
}


#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1 << 29;

int main() {
    int cash, n, w[10], c[10];
    int dp[100001];
    while (cin >> cash >> n) {
        for (int i = 0; i < n; i++)
            cin >> c[i] >> w[i];
        
        for (int i = 0; i <= cash; i++)
            dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int k = 1;
            while (k <= c[i]) {
                for (int j = cash; j >= w[i] * k; j--) {
                    dp[j] = min(dp[j], dp[j - w[i] * k] + k);
                }
                c[i] -= k;
                k *= 2;
            }
            if (c[i])
                for (int j = cash; j >= w[i] * c[i]; j--) {
                    dp[j] = min(dp[j], dp[j - w[i] * c[i]] + c[i]);
                }
        }

        for (int i = cash; ; i--) {
            if (dp[i] < INF) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

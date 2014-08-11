#include <iostream>

using namespace std;

const int INF = 1 << 20;

int main() {
    int n, t;
    cin >> n >> t;

    int v[101];
    int c[101];
    int max_v = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        max_v = max(max_v, v[i]);
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];

    // dp init
    int max_pay = max_v * max_v + t;
    int *dp1 = new int[max_pay + 1];
    int *dp2 = new int[max_pay + 1];
    for (int i = 0; i <= max_pay; i++)
        dp1[i] = dp2[i] = INF;

    // 多重背包
    dp1[0] = 0;
    for (int i = 0; i < n; i++) {
        int k = 1;
        while (k <= c[i]) { // 二进制优化
            for (int j = max_pay; j >= v[i] * k; j--)
                dp1[j] = min(dp1[j], dp1[j - v[i] * k] + k);
            c[i] -= k;
            k *= 2;
        }
        if (c[i])
            for (int j = max_pay; j >= v[i] * c[i]; j--)
                dp1[j] = min(dp1[j], dp1[j - v[i] * c[i]] + c[i]);
    }

    // 完全背包
    dp2[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= max_pay; j++) {
            dp2[j] = min(dp2[j], dp2[j - v[i]] + 1);
        }
    }

    // output
    int ans = INF;
    for (int i = t; i <= max_pay; i++) {
        ans = min(ans, dp1[i] + dp2[i - t]);
        if (ans < 0) {
            cout << i << endl;
            break;
        }
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}


#include <iostream>

using namespace std;

int main() {
    int n, m;
    int A[101];
    int C[101];
    int d[100001];

    while (cin >> n >> m and n and m) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> C[i];

        for (int i = 0; i <= m; i++)
            d[i] = -1;
        d[0] = 0;

        // 多重背包
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (d[j] >= 0)
                    d[j] = C[i];
                else if (j >= A[i] and d[j - A[i]] > 0)
                    d[j] = d[j - A[i]] - 1;
                else
                    d[j] = -1;
            }
        }

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (d[i] >= 0)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}


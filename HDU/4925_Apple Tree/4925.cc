#include <iostream>

using namespace std;

int w[102][102] = {0};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n == 1 and m == 1) {
            cout << 1 << endl;
            continue;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                w[i][j] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1 + ((i+1) % 2); j <= m; j += 2) {
                w[i][j] = 0;
                w[i-1][j] *= 2;
                w[i+1][j] *= 2;
                w[i][j-1] *= 2;
                w[i][j+1] *= 2;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                ans += w[i][j];
        }
        cout << ans << endl;
    }

    return 0;
}


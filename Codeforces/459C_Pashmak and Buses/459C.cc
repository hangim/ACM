#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int ans[1001][1001];

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    if (n > pow(k, d) + 1e-9) {
        cout << -1 << endl;
    } else {
        for (int j = 0; j < d; j++)
            ans[0][j] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < d; j++)
                ans[i][j] = ans[i-1][j];
            for (int j = d-1; j >= 0; j--) {
                ans[i][j] = (ans[i][j] + 1) % k;
                if (ans[i][j])
                    break;
            }
        }

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[j][i] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

char m[55][55];
bool r[55][55], b[55][55];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(m, 0, sizeof(m));
        memset(r, 0, sizeof(r));
        memset(b, 0, sizeof(b));

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", m[i]);
        }
        int len = strlen(m[0]);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < len; ++j) {
                if ((m[i][j] == 'R' or m[i][j] == 'G') and r[i][j] == 0) {
                    ++ans;
                    for (int k = 0; i + k < n and j + k < len; ++k) {
                        if (m[i+k][j+k] == '.' or m[i+k][j+k] == 'B')
                            break;
                        r[i+k][j+k] = 1;
                    }
                }

                if ((m[i][j] == 'B' or m[i][j] == 'G') and b[i][j] == 0) {
                    ++ans;
                    for (int k = 0; i + k < n and j - k >= 0; ++k) {
                        if (m[i+k][j-k] == '.' or m[i+k][j-k] == 'R')
                            break;
                        b[i+k][j-k] = 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


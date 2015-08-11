#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000;
int len;
int s[2 * maxn + 10];
int nRad[2 * maxn + 10];

int manacher() {
    memset(nRad, 0, sizeof(nRad));
    int maxRad = 0, j = 0, maxx = 0;
    for (int i = 1; i != len; ++i) {
        if (i < maxx)
            nRad[i] = min(nRad[2 * j - i], maxx - i);
        else
            nRad[i] = 1;
        while (s[i - nRad[i]] == s[i + nRad[i]])
            ++nRad[i];
        if (maxRad < nRad[i])
            maxRad = nRad[i];
        if (i + nRad[i] > maxx) {
            j = i;
            maxx = i + nRad[i];
        }
    }
    return maxRad - 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d", &len);

        s[0] = -2;
        s[1] = -1;
        for (int i = 0; i != len; ++i) {
            scanf("%d", &s[(i+1)*2]);
            s[(i+1)*2+1] = -1;
        }
        len = (len + 1) * 2;
        s[len] = -1;

        manacher();

        int ans = 1;
        for (int i = 1; i < len; ++i) {
            if (s[i] != -1 or i + ans + 2 - 1 >= len) continue;
            if (nRad[i] > ans) {
                for (int j = min(len - 1, i + nRad[i] - 1); j >= i + ans + 2 - 1; j -= 2) {
                    if (i + nRad[j] > j)
                        ans = max(ans, j - i + 1);
                }
            }
        }
        ans = (ans - 1) / 2 * 3;
        printf("Case #%d: %d\n", cs, ans);
    }

    return 0;
}


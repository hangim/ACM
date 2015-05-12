#include <bits/stdc++.h>

using namespace std;

int n;
int s[200010], p[200010];

int manacher() {
    memset(p, 0, sizeof(p));
    int maxP = 0, j = 0, maxx = 0;
    for (int i = 1; i != n; ++i) {
        if (i < maxx)
            p[i] = min(p[2 * j - i], maxx - i);
        else
            p[i] = 1;

        while (s[i-p[i]] == s[i+p[i]] and s[i-p[i]] <= s[i-p[i]+2])
            p[i]++;

        if (p[i] > maxP)
            maxP = p[i];

        if (i + p[i] > maxx) {
            j = i;
            maxx = i + p[i];
        }
    }
    return maxP - 1;
}

int main() {
    memset(s, 0, sizeof(s));
    s[0] = -1;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &s[i*2]);
        n = (n + 1) * 2;
        printf("%d\n", manacher());
    }
    return 0;
}


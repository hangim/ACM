#include <bits/stdc++.h>

using namespace std;

bool vis[10000000+10];
int pri[664579+10], cnt = 0;

void init() {
    for (int i = 2; i * i <= 1e7; ++i)
        if (not vis[i])
            for (int j = i * i; j <= 1e7; j += i)
                vis[j] = true;
    for (int i = 2; i <= 1e7; ++i)
        if (not vis[i])
            pri[cnt++] = i;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n;
        scanf("%lld", &n);
        int ans = 1;
        for (int i = 0; i < cnt and pri[i] <= n; ++i) {
            int t = 0;
            while (n % pri[i] == 0) {
                ++t;
                n /= pri[i];
            }
            ans *= (2 * t + 1);
        }
        if (n > 1)
            ans *= 3;
        printf("Case %d: %d\n", cs, (ans + 1) / 2);
    }
    return 0;
}


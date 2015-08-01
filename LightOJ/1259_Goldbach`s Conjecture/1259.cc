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
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < cnt and pri[i] * 2 <= n; ++i)
            if (not vis[n - pri[i]])
                ++ans;
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}


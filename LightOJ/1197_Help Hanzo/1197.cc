#include <bits/stdc++.h>

using namespace std;

bool vis[100000+10];
int pri[9592+10], cnt = 0;

void init() {
    for (int i = 2; i * i <= 1e5; ++i)
        if (not vis[i])
            for (int j = i * i; j <= 1e5; j += i)
                vis[j] = true;
    for (int i = 2; i <= 1e5; ++i)
        if (not vis[i])
            pri[cnt++] = i;
}

bool v[100000+10];

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        memset(v, 0, sizeof(v));
        for (int i = 0; i < cnt and b / pri[i] >= pri[i]; ++i) {
            for (long long j = max(a / pri[i], 2LL) * pri[i]; j <= b; j += pri[i]) {
                if (j >= a)
                    v[j-a] = true;
            }
        }
        int ans = 0;
        for (int i = max(a, 2LL); i <= b; ++i)
            if (v[i - a] == 0)
                ++ans;
        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}


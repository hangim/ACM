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

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long x;
        scanf("%lld", &x);
        bool flag = false;
        if (x < 0) {
            x = -x;
            flag = true;
        }
        int ans = 0;
        for (int i = 0; i < cnt and x / pri[i] >= pri[i]; ++i) {
            int t = 0;
            while (x % pri[i] == 0) {
                ++t;
                x /= pri[i];
            }
            ans = __gcd(ans, t);
        }
        
        if (x > 1)
            ans = 1;
        while (flag and ans % 2 == 0)
            ans /= 2;
        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

long long C2(long long n) {
    return n <= 1 ? 0 : n * (n - 1) / 2;
}

const int maxn = 1e5+10;
long long a[maxn], num[maxn], flag[maxn], cnt;

int main() {
    long long n, d1, d2;
    while (scanf("%lld %lld %lld", &n, &d1, &d2) == 3) {
        memset(a, 0, sizeof(a));
        memset(num, 0, sizeof(num));
        memset(flag, 0, sizeof(flag));
        cnt = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }

        if (a[0] + d1 == a[1]) {
            flag[cnt] = 1;
            num[cnt] = 2;
        } else if (a[0] + d2 == a[1]) {
            flag[cnt] = 2;
            num[cnt] = 2;
        } else {
            flag[cnt] = 0;
            num[cnt] = 0;
        }

        for (int i = 2; i < n; ++i) {
            if (a[i-1] + d1 == a[i]) {
                if (flag[cnt] == 1) {
                    num[cnt]++;
                } else {
                    cnt++;
                    flag[cnt] = 1;
                    num[cnt] = 2;
                }
            } else if (a[i-1] + d2 == a[i]) {
                if (flag[cnt] == 2) {
                    num[cnt]++;
                } else {
                    cnt++;
                    flag[cnt] = 2;
                    num[cnt] = 2;
                }
            } else {
                cnt++;
                flag[cnt] = 0;
                num[cnt] = 0;
            }
        }

        long long ans = n;
        for (int i = 0; i <= cnt; ++i) {
            if (flag[i]) ans += C2(num[i]);
            if (flag[i] == 1 and i != cnt and flag[i+1] == 2)
                ans += (num[i] - 1) * (num[i+1] - 1);
        }
        printf("%lld\n", ans);
    }

    return 0;
}

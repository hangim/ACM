#include <bits/stdc++.h>

using namespace std;

struct BigInt {
    const static int mod = 10000;
    const static int DLEN = 4;
    
    int a[1000], len;
    
    BigInt() {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    
    BigInt(int n) {
        memset(a, 0, sizeof(a));
        len = 0;
        do {
            a[len++] = n % mod;
            n /= mod;
        } while (n);
    }

    BigInt(const char *s) {
        memset(a, 0, sizeof(a));
        int L = strlen(s);
        len = L / DLEN + L % DLEN ? 1 : 0;
        for(int i = L - 1, k = 0; i >= 0; i -= DLEN, k++) {
            for(int j = max(i - DLEN + 1, 0); j <= i; j++)
                a[k] = a[k] * 10 + s[j] - '0';
        }
    }

    BigInt operator + (const BigInt &b) const {
        BigInt res;
        res.len = max(len, b.len);
        for (int i = 0; i < res.len; i++) {
            res.a[i] += a[i] + b.a[i];
            res.a[i + 1] += res.a[i] / mod;
            res.a[i] %= mod;
        }
        if (res.a[res.len] > 0)
            res.len++;
        return res;
    }

    BigInt operator * (const BigInt &b) const {
        BigInt res;
        res.len = len + b.len;
        for (int i = 0; i < len;i++) {
            for (int j = 0; j < b.len; j++) {
                res.a[i+j] += a[i] * b.a[j];
                res.a[i+j+1] += res.a[i+j] / mod;
                res.a[i+j] %= mod;
            }
        }
        while (res.a[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }

    void output()
    {
        printf("%d", a[len-1]);
        for (int i = len - 2; i >= 0 ; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};

const int maxn = 10000;
bool vis[maxn + 10];
int pri[maxn + 10], cnt = 0;

void init_pri() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not vis[i]) {
            for (int j = i * i; j <= maxn; j += i)
                vis[j] = true;
        }
    for (int i = 2; i <= maxn; ++i)
        if (not vis[i])
            pri[cnt++] = i;
}

int a[maxn + 10];

int main() {
    init_pri();

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        memset(a, 0, sizeof(a));

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < cnt and x >= pri[j]; j++) {
                if (x % pri[j] == 0) {
                    int t = 0;
                    while (x % pri[j] == 0) {
                        t++;
                        x /= pri[j];
                    }
                    a[j] = max(a[j], t);
                }
            }
        }
        BigInt ans(1);
        for (int i = 0; i < cnt; ++i) {
            while (a[i]) {
                ans = ans * pri[i];
                a[i]--;
            }
        }

        printf("Case %d: ", cs);
        ans.output();
    }

    return 0;
}


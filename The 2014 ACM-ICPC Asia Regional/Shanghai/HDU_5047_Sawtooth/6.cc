// C++ Accepted

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct BigInt {
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[600], len;
    
    BigInt() {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    
    BigInt(long long v) {
        memset(a, 0, sizeof(a));
        len = 0;
        do {
            a[len++] = v % mod;
            v /= mod;
        } while (v);
    }

    BigInt(const char s[]) {
        memset(a, 0, sizeof(a));
        int L = strlen(s);
        len = L / DLEN;
        if (L % DLEN)
            len++;
        int index = 0;
        for (int i = L-1; i >= 0; i -= DLEN) {
            int t = 0;
            int k = i - DLEN + 1;
            if (k < 0)
                k = 0;
            for (int j = k; j <= i; j++)
                t = t * 10 + s[j] - '0';
            a[index++] = t;
        }
    }

    BigInt operator + (const BigInt &b) const {
        BigInt res;
        res.len = max(len, b.len);
        for (int i = 0; i <= res.len; i++)
            res.a[i] = 0;
        for (int i = 0; i < res.len; i++) {
            res.a[i] += ((i < len) ? a[i] : 0) + ((i < b.len) ? b.a[i] : 0);        
            res.a[i+1] += res.a[i] / mod;
            res.a[i] %= mod;
        }
        if (res.a[res.len] > 0)
            ++res.len;
            return res;
    }

    BigInt operator * (const BigInt &b) const {
        BigInt res;
        for (int i = 0; i < len; i++) {
            int up = 0;
            for (int j = 0; j < b.len; j++) {
                int temp = a[i] * b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp % mod;
                up = temp / mod;
            }
            if (up != 0)
                res.a[i+b.len] = up;
        }
        res.len = len + b.len;
        while (res.a[res.len - 1] == 0 && res.len > 1)
            --res.len;
        return res;
    }

    void output() {
        printf("%d", a[len-1]);
        for (int i = len-2; i >= 0; i--)
            printf("%04d", a[i]);
        printf("\n");
    }
};

int main() {
    BigInt A;
    BigInt one(1);

    int t;
    scanf("%d", &t);
    for (int index = 1; index <= t; index++) {
        long long n;
        scanf("%I64d", &n);
        A = (BigInt(8 * n - 7) * BigInt(n)) + one;
        printf("Case #%d: ", index);
        A.output();
    }

    return 0;
}


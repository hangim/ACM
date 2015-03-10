#include <bits/stdc++.h>

using namespace std;

const int MaxN = 70;
const int MaxM = 70;
const int MaxNode = MaxN * MaxM;

struct DLX {
    int n, m, size;
    int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode];
    int Col[MaxNode], H[MaxN], S[MaxM];
    
    void init(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i <= m; ++i) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        L[0] = m;
        R[m] = 0;
        size = m;
        for (int i = 1; i <= n; ++i)
            H[i] = -1;
    }

    void link(int r, int c) {
        ++S[Col[++size] = c];
        D[size] = c;
        U[size] = U[c];
        D[U[c]] = size;
        U[c] = size;
        if (H[r] == -1) {
            H[r] = L[size] = R[size] = size;
        } else {
            L[size] = L[H[r]];
            R[size] = H[r];
            R[L[H[r]]] = size;
            L[H[r]] = size;
        }
    }

    void reMove(int c) {
        for (int i = D[c]; i != c; i = D[i])
            R[L[i]] = R[i], L[R[i]] = L[i];
    }

    void reSume(int c) {
        for (int i = D[c]; i != c; i = D[i])
            R[L[i]] = L[R[i]] = i;
    }

    bool V[MaxM];
    
    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c])
            V[c] = true;
        for (int c = R[0]; c != 0; c = R[c]) {
            if (V[c]) {
                ++ret;
                V[c] = false;
                for (int i = D[c]; i != c; i = D[i])
                    for (int j = R[i]; j != i; j = R[j])
                        V[Col[j]] = false;
            }
        }
        return ret;
    }

    bool dance(int d, int k) {
        if (d + f() > k)
            return false;
        if (R[0] == 0)
            return true;

        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if (S[i] < S[c])
                c = i;
        }

        for (int i = D[c]; i != c; i = D[i]) {
            reMove(i);
            for (int j = R[i]; j != i; j = R[j])
                reMove(j);
            if (dance(d + 1, k))
                return true;
            for (int j = R[i]; j != i; j = R[j])
                reSume(j);
            reSume(i);
        }
        return false;
    }
};

struct Point {
    long long x, y;
} City[70];

long long D[70][70];

DLX dlx;

int main() {
    int t;
    scanf("%d", &t);

    for (int cases = 1; cases <= t; ++cases) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &City[i].x, &City[i].y);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                D[i][j] = abs(City[i].x - City[j].x) + abs(City[i].y - City[j].y);
            }
        }

        long long l = 0LL, r = 40LL * 10000 * 10000;
        while (r > l) {
            long long mid = (l + r) / 2;
            dlx.init(n, n);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (D[i][j] <= mid)
                        dlx.link(i, j);
                }
            }

            if (dlx.dance(0, k))
                r = mid;
            else
                l = mid + 1;
        }

        printf("Case #%d: %lld\n", cases, r);
    }

    return 0;
}

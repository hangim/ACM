#include <bits/stdc++.h>

using namespace std;

const int MaxN = 80;
const int MaxM = 80;
const int MaxNode = MaxN * MaxM;
const int INF = 1e9;

struct DLX {
    int n, m, size;
    int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode];
    int Col[MaxNode], H[MaxN], S[MaxM];
    int ansd;

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
        ansd = INF;
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
        for (int i = D[c]; i != c; i = D[i]) {
            R[L[i]] = R[i];
            L[R[i]] = L[i];
        }
    }

    void reSume(int c) {
        for (int i = D[c]; i != c; i = D[i]) {
            R[L[i]] = L[R[i]] = i;
        }
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

    void dance(int d) {
        if (d + f() >= ansd)
            return;
        if (R[0] == 0) {
            ansd = min(ansd, d);
            return;
        }

        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if (S[i] < S[c])
                c = i;
        }

        for (int i = D[c]; i != c; i = D[i]) {
            reMove(i);
            for (int j = R[i]; j != i; j = R[j])
                reMove(j);
            dance(d + 1);
            for (int j = R[i]; j != i; j = R[j])
                reSume(j);
            reSume(i);
        }
    }
};

DLX dlx;
int A[256], B[256];

int g(int n, int m, int k) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i < (1<<n); ++i) {
        int ret = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                ++ret;
        }
        if (ret == m)
            A[++cnt1] = i;
        if (ret == k)
            B[++cnt2] = i;
    }

    dlx.init(cnt1, cnt2);
    for (int i = 1; i <= cnt1; ++i) {
        for (int j = 1; j <= cnt2; ++j) {
            if ((A[i] | B[j]) == A[i])
                dlx.link(i, j);
        }
    }

    dlx.dance(0);
    return dlx.ansd;
}

int main() {
    freopen("out", "w", stdout);

    for (int n = 0; n <= 8; ++n) {
        for (int m = 0; m <= 8; ++m) {
            for (int r = 0; r <= 8; ++r) {
                if (n >= m and m >= r and r >= 1)
                    printf("%d, ", g(n, m, r));
                else
                    printf("0, ");
            }
        }
    }

    return 0;
}


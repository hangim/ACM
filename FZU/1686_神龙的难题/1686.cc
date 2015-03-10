#include <cstdio>

const int MaxN = 15 * 15 + 10;
const int MaxM = 15 * 15 + 10;
const int MaxNode = MaxN * MaxM;
const int INF = 1e9;

struct DLX {
    int n, m, size;
    int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode], Col[MaxNode]; // Row[MaxNode];
    int H[MaxN], S[MaxM];
    int ansd; // ans[MaxNode];
    
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
        ansd = -1;
    }

    void link(int r, int c) {
        ++S[Col[++size] = c];
        // Row[size] = r;
        D[size] = D[c];
        U[size] = c;
        U[D[c]] = size;
        D[c] = size;
        if (H[r] == -1) {
            H[r] = L[size] = R[size] = size;
        } else {
            R[size] = H[r];
            L[size] = L[H[r]];
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
        for (int i = D[c]; i != c; i = D[i])
            R[L[i]] = L[R[i]] = i;
    }

    bool v[MaxM];

    int f() {
        int ret = 0;
        for (int c = R[0]; c != 0; c = R[c])
            v[c] = true;
        for (int c = R[0]; c != 0; c = R[c]) {
            if (v[c]) {
                ++ret;
                v[c] = false;
                for (int i = D[c]; i != c; i = D[i])
                    for (int j = R[i]; j != i; j = R[j])
                        v[Col[j]] = false;
            }
        }
        return ret;
    }

    void dance(int d) {
        if (ansd != -1 and d + f() >= ansd)
            return;
        if (R[0] == 0) {
            if (ansd == -1 or d < ansd)
                ansd = d;
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

int A[15][15];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int sz = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                scanf("%d", &A[i][j]);
                if (A[i][j])
                    A[i][j] = ++sz;
            }
        }
        dlx.init(n * m, sz);

        int n1, m1;
        scanf("%d %d", &n1, &m1);
        sz = 1;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                for (int x = 0; x != n1 and i + x != n; ++x) {
                    for (int y = 0; y != m1 and j + y != m; ++y) {
                        if (A[i + x][j + y])
                            dlx.link(sz, A[i + x][j + y]);
                    }
                }
                ++sz;
            }
        }

        dlx.dance(0);
        printf("%d\n", dlx.ansd);
    }

    return 0;
}


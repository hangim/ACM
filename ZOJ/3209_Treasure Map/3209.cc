#include <bits/stdc++.h>

using namespace std;

const int MaxRow = 510;
const int MaxCol = 910;
const int MaxNode = 500 * 900 + MaxCol + 10;
const int INF = 1e9;

struct DLX {
    int n, m, size;
    int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode],
        Row[MaxNode], Col[MaxNode], H[MaxRow], S[MaxRow];
    int ans[MaxRow], ansd;

    void init(int n, int m) {
        ansd = INF;
        this->n = n;
        this->m = m;
        for (int i = 0; i <= m; ++i) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        L[0] = m;
        R[m] = 0;
        size = m;
        for (int i = 1; i <= n; ++i) {
            H[i] = -1;
        }
    }

    void link(int r, int c) {
        ++S[Col[++size] = c];
        Row[size] = r;
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
        // --S[c];
        R[L[c]] = R[c];
        L[R[c]] = L[c];
        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                --S[Col[j]];
                D[U[j]] = D[j];
                U[D[j]] = U[j];
            }
        }
    }

    void reSume(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            for (int j = L[i]; j != i; j = L[j]) {
                ++S[Col[D[U[j]] = U[D[j]] = j]];
            }
        }
        R[L[c]] = L[R[c]] = c;
        // ++S[c];
    }

    bool dance(int d) {
        if (d >= ansd)
            return false; // 剪枝

        if (R[0] == 0) {
            ansd = min(d, ansd);
            return true;
        }

        bool flag = false;
        int c = R[0];
        for (int i = R[c]; i != 0; i = R[i]) { // 加速
            if (S[i] < S[c])
                c = i;
        }

        reMove(c);
        for (int i = D[c]; i != c; i = D[i]) {
            //ans[d] = Row[i];
            for (int j = R[i]; j != i; j = R[j]) {
                reMove(Col[j]);
            }
            if (dance(d + 1))
                flag = true;
            for (int j = L[i]; j != i; j = L[j])
                reSume(Col[j]);
        }
        reSume(c);

        return flag;
    }

    int getAnser() {
        return ansd;
    }
};

DLX dlx;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, p;
        scanf("%d %d %d", &n, &m, &p);
        dlx.init(p, n * m);
        for (int i = 1; i <= p; ++i) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for (int x = x1 + 1; x <= x2; ++x) {
                for (int y = y1 + 1; y <= y2; ++y) {
                    dlx.link(i, x + (y - 1) * n);
                }
            }
        }

        if (dlx.dance(0))
            printf("%d\n", dlx.getAnser());
        else
            printf("%d\n", -1);
    }

    return 0;
}


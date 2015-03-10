#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1010;
const int kMaxNode = 100010;

struct DLX {
    int n, m, size;
    int U[kMaxNode], D[kMaxNode], L[kMaxNode], R[kMaxNode],
        Row[kMaxNode], Col[kMaxNode];
    int H[kMaxN], S[kMaxN]; // H 表头 S 大小
    int ansd, ans[kMaxN];

    void Init(int n, int m) {
        this->n = n;
        this->m = m;
        for (int i = 0; i <= m; i++) {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0;
        L[0] = m;
        size = m;
        for (int i = 1; i <= n; i++)
            H[i] = -1;
    }

    void Link(int r, int c) {
        ++S[Col[++size] = c];
        Row[size] = r;
        D[size] = D[c]; // 从下向上添加
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if (H[r] < 0) {
            H[r] = L[size] = R[size] = size;
        } else {
            L[size] = L[H[r]]; // 从左向右添加
            R[L[H[r]]] = size;
            R[size] = H[r];
            L[H[r]] = size;
        }
    }

    void ReMove(int c) {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        for (int i = D[c]; i != c; i = D[i]) {
            for (int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }
        }
    }

    void ReSume(int c) {
        for (int i = U[c]; i != c; i = U[i]) {
            for (int j = L[i]; j != i; j = L[j]) {
                U[D[j]] = D[U[j]] = j;
                ++S[Col[j]];
            }
        }
        L[R[c]] = R[L[c]] = c;
    }

    bool Dance(int d) {
        if (R[0] == 0) {
            printf("%d", d);
            for (int i = 0; i < d; i++) {
                printf(" %d", ans[i]);
            }
            printf("\n");
            return true;
        }
        int c = R[0];
        for (int i = R[0]; i != 0; i = R[i]) {
            if (S[i] < S[c])
                c = i; // 查找最少？
        }
        ReMove(c);
        for (int i = D[c]; i != c; i = D[i]) {
            ans[d] = Row[i];
            for (int j = R[i]; j != i; j = R[j])
                ReMove(Col[j]);
            if (Dance(d + 1))
                return true;
            for (int j = L[i]; j != i; j = L[j])
                ReSume(Col[j]);
        }
        ReSume(c);
        return false;
    }
};


int n, m;
DLX dlx;

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        dlx.Init(n, m);
        for (int i = 1; i <= n; i++) {
            int cnt_tmp;
            scanf("%d", &cnt_tmp);
            int tmp;
            while (cnt_tmp--) {
                scanf("%d", &tmp);
                dlx.Link(i, tmp);
            }
        }

        if (not dlx.Dance(0))
            printf("NO\n");
    }

    return 0;
}


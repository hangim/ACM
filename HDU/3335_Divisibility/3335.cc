#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1010;
const int MaxM = 1010;
const int MaxNode = MaxN * MaxM;

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
        ansd = -1;
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
        if (d + f() <= ansd)
            return;
        if (R[0] == 0) {
            ansd = max(ansd, d);
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
long long Num[1010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dlx.init(n, n);
        for (int i = 1; i <= n; ++i)
            cin >> Num[i];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                if (Num[i] % Num[j] == 0LL or Num[j] % Num[i] == 0LL) {
                    dlx.link(i, j);
                    dlx.link(j, i);
                }
            }
        }
        dlx.dance(0);
        cout << dlx.ansd << endl;
    }
    
    return 0;
}


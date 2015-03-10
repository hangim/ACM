#include <cstdio>
#include <cmath>

const int MaxN = 51;
const int MaxM = 51;
const int MaxNode = MaxN * MaxM;

struct DLX {
    int n, m, size;
    int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode], Col[MaxNode];
    int H[MaxN], S[MaxM];
    
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

    bool dance(int d, int k) {
        if (d + f() > k)
            return false;
        if (R[0] == 0) {
            return true;
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
            if (dance(d + 1, k))
                return true;
            for (int j = R[i]; j != i; j = R[j])
                reSume(j);
            reSume(i);
        }
        return false;
    }
};

DLX dlx;

struct Point {
    double x, y;
} City[51], Radar[51];
double Dis[51][51];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 1; i <= m; ++i)
            scanf("%lf %lf", &City[i].x, &City[i].y);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &Radar[i].x, &Radar[i].y);
            for (int j = 1; j <= m; ++j) {
                Dis[i][j] = hypot(Radar[i].x - City[j].x, Radar[i].y - City[j].y);
            }
        }

        double l = 0, r = hypot(1000, 1000);
        while (r - l > 1e-8) {
            double mid = (l + r) / 2;
            dlx.init(n, m);
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (Dis[i][j] < mid) {
                        dlx.link(i, j);
                    }
                }
            }

            if (dlx.dance(0, k))
                r = mid;
            else
                l = mid;
        }
        printf("%.6lf\n", r);
    }

    return 0;
}


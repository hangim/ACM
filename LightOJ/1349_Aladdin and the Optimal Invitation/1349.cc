#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, n;
    bool operator < (const Node &o) const {
        return x < o.x;
    }
} U[50010], V[50010];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int m, n, q;
        scanf("%d %d %d", &m, &n, &q);
        int u, v, w, uu, vv, ww = 0;
        for (int i = 0; i < q; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            U[i].x = u;
            U[i].n  = w;
            V[i].x = v;
            V[i].n = w;
            ww += w;
        }
        sort(U, U + q);
        sort(V, V + q);

        for (int i = 0, tu = 0; i < q; ++i) {
            tu += U[i].n;
            if (tu >= (ww + 1) / 2) {
                uu = U[i].x;
                break;
            }

        }
        for (int i = 0, tv = 0; i < q; ++i) {
            tv += V[i].n;
            if (tv >= (ww + 1) / 2) {
                vv = V[i].x;
                break;
            }
        }

        printf("Case %d: %d %d\n", cs, uu, vv);
    }
    return 0;
}


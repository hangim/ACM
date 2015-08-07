#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
int Next[maxn + 10], f[maxn + 10];

void init(int n) {
    for (int i = 1; i <= n; ++i)
        f[i] = i, Next[i] = i + 1;
}

int Find(int x) {
    return x == f[x] ? x : (f[x] = Find(f[x]));
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    f[fx] = f[fy] = min(fx, fy);
}

void Merge(int l, int r) {
    for (int i = l + 1; i <= r; ) {
        Union(i, i - 1);
        int k = Next[i];
        Next[i] = Next[r];
        i = k;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            Union(x, y);
        } else if (cmd == 2) {
            Merge(x, y);
        } else if (cmd == 3) {
            puts(Find(x) == Find(y) ? "YES" : "NO");
        }
    }

    return 0;
}


#include <cstdio>

int n;
int v[100001];

int search(int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return v[l] <= x ? l + 1 : l;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int k = 1; k <= t; ++k) {
        int q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i != n; ++i)
            scanf("%d", &v[i]);

        printf("Case %d:\n", k);
        for (int i = 0; i != q; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", search(b) - search(a - 1));
        }
    }

    return 0;
}


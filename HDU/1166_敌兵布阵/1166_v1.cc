#include <cstdio>
#include <cstring>

using namespace std;

int m[(50000 + 10) * 4];

void build(int l, int r, int now) {
    if (l == r) {
        scanf("%d", &m[now]);
        return;
    }

    int mid = l + (r - l) / 2;
    build(l, mid, now * 2);
    build(mid + 1, r, now * 2 + 1);
    m[now] = m[now * 2] + m[now * 2 + 1];
}

int sum(int a, int b, int l, int r, int now) {
    if (a <= l and r <= b)
        return m[now];
    
    int mid = l + (r - l) / 2;
    int ans = 0;
    if (a <= mid)
        ans += sum(a, b, l, mid, now * 2);
    if (mid < b)
        ans += sum(a, b, mid + 1, r, now * 2 + 1);
    return ans;
}

void add(int pos, int val, int l, int r, int now) {
    m[now] += val;
    if (l == r)
        return;
    
    int mid = l + (r - l) / 2;
    if (pos <= mid)
        add(pos, val, l, mid, now * 2);
    if (mid < pos)
        add(pos, val, mid + 1, r, now * 2 + 1);
}

void sub(int pos, int val, int l, int r, int now) {
    m[now] -= val;
    if (l == r)
        return;

    int mid = l + (r - l) / 2;
    if (pos <= mid)
        sub(pos, val, l, mid, now * 2);
    if (mid < pos)
        sub(pos, val, mid + 1, r, now * 2 + 1);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int k = 1; k <= t; k++) {
        memset(m, 0, sizeof(m));

        int n;
        scanf("%d", &n);

        build(1, n, 1);

        printf("Case %d:\n", k);

        char op[10];
        while (scanf("%s", op)) {
            int a, b;
            if (op[0] == 'Q') {
                scanf("%d%d", &a, &b);
                printf("%d\n", sum(a, b, 1, n, 1));
            } else if (op[0] == 'A') {
                scanf("%d%d", &a, &b);
                add(a, b, 1, n, 1);
            } else if (op[0] == 'S') {
                scanf("%d%d", &a, &b);
                sub(a, b, 1, n, 1);
            } else {
                break;
            }
        }
    }

    return 0;
}


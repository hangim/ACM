#include <cstdio>

int lsum[50000<<2];
int rsum[50000<<2];
int msum[50000<<2];
int flag[50000<<2]; // 1 住满, 0 全空, -1 未定义

int max(int a, int b) {
    return a > b ? a : b;
}

void push_up(int l, int r, int rt) {
    int mid = (l+r)>>1;
    
    lsum[rt] = lsum[rt<<1];
    if (lsum[rt] == mid-l+1)
        lsum[rt] += lsum[rt<<1|1];

    rsum[rt] = rsum[rt<<1|1];
    if (rsum[rt] == r-mid)
        rsum[rt] += rsum[rt<<1];

    msum[rt] = max(rsum[rt<<1] + lsum[rt<<1|1],
                   max(msum[rt<<1], msum[rt<<1|1]));
}

void push_down(int l, int r, int rt) {
    if (flag[rt] == -1)
        return;

    int mid = (l+r)>>1;
    lsum[rt<<1] = rsum[rt<<1] = msum[rt<<1]
        = (flag[rt]) ? 0 : mid - l + 1;
    lsum[rt<<1|1] = rsum[rt<<1|1] = msum[rt<<1|1]
        = (flag[rt]) ? 0 : r - mid;
    flag[rt<<1] = flag[rt<<1|1] = flag[rt];

    flag[rt] = -1;
}

void build (int l, int r, int rt) {
    flag[rt] = -1;
    if (l == r) {
        lsum[rt] = rsum[rt] = msum[rt] = 1;
        return;
    }

    int mid = (l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);

    push_up(l, r, rt);
}

int query(int n, int l, int r, int rt) {
    if (msum[rt] < n)
        return 0;

    if (l == r)
        return l;

    push_down(l, r, rt);

    int mid = (l+r)>>1;
    if (msum[rt<<1] >= n)
        return query(n, l, mid, rt<<1);
    if (rsum[rt<<1] + lsum[rt<<1|1] >= n)
        return mid - rsum[rt<<1] + 1;
    return query(n, mid+1, r, rt<<1|1);
}

void update(int a, int b, int c, int l, int r, int rt) {
    if (a <= l and r <= b) {
        lsum[rt] = rsum[rt] = msum[rt] = c ? 0 : r - l + 1;
        flag[rt] = c;
        return;
    }

    push_down(l, r, rt);

    int mid = (l+r)>>1;
    if (a <= mid)
        update(a, b, c, l, mid, rt<<1);
    if (mid < b)
        update(a, b, c, mid+1, r, rt<<1|1);

    push_up(l, r, rt);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    build(1, n, 1);
    
    while (m--) {
        int op, a, b;
        scanf("%d", &op);
        if (op == 1) { // check in
            scanf("%d", &a);
            int pos = query(a, 1, n, 1);
            if (pos != 0)
                update(pos, pos+a-1, 1, 1, n, 1);
            printf("%d\n", pos);
        } else { // check out
            scanf("%d%d", &a, &b);
            update(a, a+b-1, 0, 1, n, 1);
        }
    }

    return 0;
}


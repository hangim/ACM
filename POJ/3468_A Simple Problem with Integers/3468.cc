#include <cstdio>

struct Number {
    long long val;
    long long delta;
} num[100000<<2];

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%lld", &num[rt].val);
        num[rt].delta = 0;
        return;
    }

    int mid = (l + r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);

    num[rt].val = num[rt<<1].val + num[rt<<1|1].val;
    num[rt].delta = 0;
}

void update(int a, int b, long long val, int l, int r, int rt) {
    if (a <= l and r <= b) {
        num[rt].val += val * (r - l + 1);
        if (l != r)
            num[rt].delta += val; // not leaf
        return;
    }

    int mid = (l + r)>>1;
    if (num[rt].delta) {
        num[rt<<1].val += num[rt].delta * (mid - l + 1);
        num[rt<<1].delta += num[rt].delta;
        num[rt<<1|1].val += num[rt].delta * (r - mid);
        num[rt<<1|1].delta += num[rt].delta;
        num[rt].delta = 0;
    }

    if (a <= mid)
        update(a, b, val, l, mid, rt<<1);
    if (mid < b)
        update(a, b, val, mid+1, r, rt<<1|1);

    num[rt].val = num[rt<<1].val + num[rt<<1|1].val;
}

long long sum(int a, int b, int l, int r, int rt) {
    if (a <= l and r <= b) {
        return num[rt].val;
    }

    int mid = (l + r)>>1;
    if (num[rt].delta) {
        num[rt<<1].val += num[rt].delta * (mid - l + 1);
        num[rt<<1].delta += num[rt].delta;
        num[rt<<1|1].val += num[rt].delta * (r - mid);
        num[rt<<1|1].delta += num[rt].delta;
        num[rt].delta = 0;
    }

    long long ans = 0;
    if (a <= mid)
        ans += sum(a, b, l, mid, rt<<1);
    if (mid < b)
        ans += sum(a, b, mid+1, r, rt<<1|1);

    return ans; 
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    build(1, n, 1);

    for (int i = 0; i < q; i++) {
        char op[10];
        int a, b;
        long long c;
        scanf("%s", op);
        if (op[0] == 'Q') {
            scanf("%d%d", &a, &b);
            printf("%lld\n", sum(a, b, 1, n, 1));
        } else {
            scanf("%d%d%lld", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
    }
    
    return 0;
}


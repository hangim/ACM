#include <cstdio>
#include <cstring>

int n;
int m[50001];

inline int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    while (x <= n) {
        m[x] += val;
        x += lowbit(x);
    }
}

int sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += m[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int k = 1; k <= t; k++) {
        printf("Case %d:\n", k);

        memset(m, 0, sizeof(m));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int val;
            scanf("%d", &val);
            update(i, val);
        }

        char op[10];
        while (scanf("%s", op)) {
            if (op[0] == 'E')
                break;

            int i, j;
            scanf("%d%d", &i, &j);
            if (op[0] == 'A') {
                update(i, j);
            } else if (op[0] == 'S') {
                update(i, -j);
            } else if (op[0] == 'Q') {
                printf("%d\n", sum(j) - sum(i-1));
            }
        }
    }

    return 0;
}


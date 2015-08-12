#include <bits/stdc++.h>

using namespace std;

long long c2(int n) {
    return (long long) n * (n - 1) / 2;
}

struct Node {
    int x, y;
    bool operator == (const Node &o) const {
        return x == o.x and y == o.y;
    }
    bool operator < (const Node &o) const {
        if (x == o.x)
            return y < o.y;
        return x < o.x;
    }
} point[1010], node[1000000];

int cnt;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &point[i].x, &point[i].y);
        
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                node[cnt].x = point[i].x + point[j].x;
                node[cnt].y = point[i].y + point[j].y;
                cnt++;
            }
        }
        sort(node, node + cnt);

        long long ans = 0;
        for (int i = 1, j = 1; i < cnt; ++i) {
            if (node[i] == node[i-1]) {
                j++;
            } else {
                if (j >= 2)
                    ans += c2(j);
                j = 1;
            }
            if (i == cnt - 1 and j >= 2)
                ans += c2(j);
        }

        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


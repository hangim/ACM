#include <bits/stdc++.h>

using namespace std;

int init[110][110], goal[110][110];
int visH[110], visL[110], vis[510];
int ans[510];

struct Node {
    char op[2];
    int x, y;
} node[510];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &init[i][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &goal[i][j]);
        for (int i = 0; i < m; ++i)
            scanf("%s%d%d", node[i].op, &node[i].x, &node[i].y);

        memset(visH, 0, sizeof(visH));
        memset(visL, 0, sizeof(visL));
        memset(vis, 0, sizeof(vis));

        for (int cnt = 0; cnt < m; ) {
            for (int i = 0; i < m; ++i) {
                if (vis[i]) continue;
                if (node[i].op[0] == 'L') {
                    if (visL[node[i].x]) {
                        vis[i] = 1;
                        ans[m - cnt++ - 1] = i + 1;
                        continue;
                    }
                    bool flag = true;
                    for (int j = 1; flag and j <= n; ++j)
                        if (not visH[j] and goal[j][node[i].x] != node[i].y)
                            flag = false;
                    if (flag) {
                        visL[node[i].x] = 1;
                        vis[i] = 1;
                        ans[m - cnt++ - 1] = i + 1;
                    }
                } else {
                    if (visH[node[i].x]) {
                        vis[i] = 1;
                        ans[m - cnt++ - 1] = i + 1;
                        continue;
                    }
                    bool flag = true;
                    for (int j = 1; flag and j <= n; ++j)
                        if (not visL[j] and goal[node[i].x][j] != node[i].y)
                            flag = false;
                    if (flag) {
                        visH[node[i].x] = 1;
                        vis[i] = 1;
                        ans[m - cnt++ - 1] = i + 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}


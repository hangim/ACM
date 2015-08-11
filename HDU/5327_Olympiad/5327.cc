#include <bits/stdc++.h>

using namespace std;

bool vv[100010];

int vis[10];
void dfs(int x, int num) {
    if (x == 6)
        return;
    vv[num] = 1;
    for (int i = 0; i < 10; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(x + 1, num * 10 + i);
        vis[i] = 0;
    }
}

int cnt[100010];

int main() {
    for (int i = 1; i <= 9; ++i) {
        vis[i] = 1;
        dfs(1, i);
        vis[i] = 0;
    }
    vv[100000] = 0;
    //for (int i = 1; i <= 100; ++i)
    //    cout << i << " - " << vv[i] << endl;

    cnt[0] = 0;
    for (int i = 1; i <= 100000; ++i)
        cnt[i] = cnt[i-1] + vv[i];

    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", cnt[b] - cnt[a-1]);
    }
    return 0;
}


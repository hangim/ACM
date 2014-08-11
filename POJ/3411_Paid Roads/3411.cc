#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;
struct Edge {
    int b, c, p, r;
};
vector<struct Edge> e[11];
int dp[11][1<<10];
int n;

void spfa() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = INF;

    dp[1][1] = 0;

    queue<int> q;
    q.push(1);

    while (not q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < e[f].size(); i++) { // 更新与 f 相邻的顶点
            struct Edge &t = e[f][i];
            
            for (int j = 0; j < (1 << n); j++) { // 用 dp[f][j] 更新
                if (j & (1 << f - 1) == 0)
                    continue; // 没有经过 f 点

                int pos = t.b; // 下一个点
                int mask = j | (1 << (t.b - 1)); // 下一个状态
                
                if (j & (1 << (t.c - 1))) { // 经过 c 点
                    if (dp[pos][mask] > dp[f][j] + t.p) {
                        dp[pos][mask] = dp[f][j] + t.p;
                        q.push(pos);
                    }
                } else { // 没有经过 c 点
                    if (dp[pos][mask] > dp[f][j] + t.r) {
                        dp[pos][mask] = dp[f][j] + t.r;
                        q.push(pos);
                    }
                }
            }
            
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
   
    // input
    for (int i = 0; i < m; i++) {
        int a, b, c, p, r;
        cin >> a >> b >> c >> p >> r;
        struct Edge road = {b, c, p, r};
        e[a].push_back(road);
    }

    // solve
    spfa();

    int ans = INF;
    for (int i = 0; i < (1 << n); i++) {
        if (i & 1 and i & (1 << (n-1)))
            ans = min(ans, dp[n][i]);
    }
    
    // output
    if (ans == INF)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1 << 20;
int dp[13][2];

int main() {
    int n;
    while (scanf("%d", &n) == 1 and n != 0) {
        map<int, int> m;
        for (int i = 0; i != n; ++i) {
            int x, t;
            scanf("%d%d", &x, &t);
            ++x; // 整体右平移
            ++m[t * 100 + x]; // hash(t, x)
        }
        for (int i = 1; i != 100000; ++i) // 时间连续
            m[i * 100 + 0] = 0;

        for (int i = 0; i != 13; ++i)
            dp[i][0] = dp[i][1] = -INF;

        dp[6][0] = 0;
        
        int time = -1;
        int now = 0, last = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            int t = it->first / 100;
            int x = it->first % 100;
            int many = it->second;
            if (time != t) {
                time = t;
                last = now;
                now = (now + 1) % 2;
                for (int i = 1; i <= 11; ++i)
                    dp[i][now] = max(dp[i][last], max(dp[i-1][last], dp[i+1][last]));
            }
            dp[x][now] = max(dp[x][last], max(dp[x-1][last], dp[x+1][last])) + many;
        }

        int ans = 0;
        for (int i = 1; i <= 11; ++i)
            ans = max(ans, dp[i][now]);
        printf("%d\n", ans);
    }

    return 0;
}


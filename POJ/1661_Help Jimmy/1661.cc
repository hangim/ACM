#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x1, x2, h;
    Node (int _x1, int _x2, int _h) : x1(_x1), x2(_x2), h(_h) {}
    bool operator < (const Node &o) const {
        return h > o.h;
    }
};

const int INF = 1e8;
vector<Node> v;
int dp[1010][2];

int main() {
    int t;
    cin >> t;
    while (t--) {
        v.clear();

        int n, x, y, max_h;
        cin >> n >> x >> y >> max_h;
        v.push_back(Node(x, x, y));
        
        for (int i = 0; i != n; ++i) {
            int x1, x2, h;
            cin >> x1 >> x2 >> h;
            v.push_back(Node(x1, x2, h));
        }
        sort(v.begin() + 1, v.end());
        
        for (int i = 1; i <= n; ++i)
            dp[i][0] = dp[i][1] = INF;
        dp[0][0] = dp[0][1] = y;

        // 暴力DP
        for (int i = 0; i != v.size(); ++i) {
            bool flagl = false, flagr = false;
            for(int j = i + 1; j != v.size(); ++j) {
                if (v[i].h <= v[j].h)
                    continue;
                if (v[i].h - v[j].h > max_h)
                    break;

                if (not flagl and v[i].x1 >= v[j].x1 and v[i].x1 <= v[j].x2) {
                    dp[j][0] = min(dp[j][0], dp[i][0] + v[i].x1 - v[j].x1);
                    dp[j][1] = min(dp[j][1], dp[i][0] + v[j].x2 - v[i].x1);
                    flagl = true;
                }

                if (not flagr and v[i].x2 >= v[j].x1 and v[i].x2 <= v[j].x2) {
                    dp[j][0] = min(dp[j][0], dp[i][1] + v[i].x2 - v[j].x1);
                    dp[j][1] = min(dp[j][1], dp[i][1] + v[j].x2 - v[i].x2);
                    flagr = true;
                }

                if (flagl and flagr)
                    break;
            }
        }

        // 寻找答案
        int ans = INF;
        for (int i = 0; i != v.size(); ++i) {
            if (v[i].h > max_h)
                continue;

            bool flag = true;
            for (int j = i + 1; j != v.size(); ++j) {
                if (v[i].h == v[j].h)
                    continue;
                if (v[i].x1 >= v[j].x1 and v[i].x1 <= v[j].x2) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans = min(ans, dp[i][0]);

            flag = true;
            for (int j = i + 1; j != v.size(); ++j) {
                if (v[i].h == v[j].h)
                    continue;
                if (v[i].x2 >= v[j].x1 and v[i].x2 <= v[j].x2) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans = min(ans, dp[i][1]);
        }
        cout << ans << endl;
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int Max_Node = 1 << 16;

struct Dp {
    int pre;
    int time;
    int penalty;
} dp[Max_Node];

struct Course {
    string name;
    int deadline;
    int last;
} course[15];

bool vis[Max_Node];

void print_path(int status) {
    if (dp[status].pre != 0)
        print_path(dp[status].pre);
    int ret = status ^ dp[status].pre;
    for (int j = 0; j != 16; ++j) {
        if (ret & 1 << j)
            cout << course[j].name << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;
        for (int i = 0; i != n; ++i)
            cin >> course[i].name >> course[i].deadline >> course[i].last;

        dp[0].pre = -1;
        dp[0].time = 0;
        dp[0].penalty = 0;
        vis[0] = 1;

        for (int i = 0; i != (1<<n) - 1; ++i) {
            for (int j = 0; j != n; ++j) {
                if (i & 1 << j) continue;

                int next = i | 1 << j;
                int time = dp[i].time + course[j].last;
                int penalty = dp[i].penalty + max(0, time - course[j].deadline);
                if (not vis[next] or penalty < dp[next].penalty) {
                    dp[next].pre = i;
                    dp[next].time = time;
                    dp[next].penalty = penalty;
                    vis[next] = true;
                }
            }
        }

        cout << dp[(1 << n) - 1].penalty << endl;
        print_path((1 << n) - 1);
    }

    return 0;
}


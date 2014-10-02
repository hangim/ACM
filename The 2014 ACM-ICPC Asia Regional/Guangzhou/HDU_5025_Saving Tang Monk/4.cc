// 思路有误, 可构造数据报错

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <iomanip>

using namespace std;

int m[102][102];
int vis[102][102];

struct Node {
    int x, y;
    int state;
    int step;
    Node (int _x, int _y, int _state, int _step) {
        x = _x, y = _y, state = _state, step = _step;
    }
};
vector<Node> dp[11];
map<int, int> snake;

int hash(int x, int y) {
    return x * 102 + y;
}

void bfs(Node now) {
    static int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

    int next = m[now.x][now.y] + 1;
    memset(vis, 0, sizeof(vis));

    queue<Node> q;
    q.push(now);
    vis[now.x][now.y] = 1;

    while (not q.empty()) {
        Node x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = x.x + dir[i][0];
            int next_y = x.y + dir[i][1];
            if (vis[next_x][next_y] or m[next_x][next_y] == -1)
                continue;
            vis[next_x][next_y] = 1;

            int next_step = x.step + 1;
            int next_state = x.state;
            if (m[next_x][next_y] == 99) {
                int tmp = 1 << snake[hash(next_x, next_y)];
                if ((next_state & tmp) == 0) {
                    // cout << "kill" << endl;
                    next_step++;
                    next_state |= tmp;
                }
            }
            q.push(Node(next_x, next_y, next_state, next_step));
        }
        
        if (m[x.x][x.y] == next) {
            bool flag = true;
            for (int i = 0; i < dp[next].size(); i++) {
                if (x.state == dp[next][i].state) {
                    dp[next][i].step = min(x.step, dp[next][i].step);
                    flag = false;
                }
            }
            if (flag)
                dp[next].push_back(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    
    while (cin >> n >> k and n + k) {
        for (int i = 0; i < 11; i++)
            dp[i].clear();
        snake.clear();
        memset(m, -1, sizeof(m));
        
        string line;
        int snake_cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> line;
            for (int j = 1; j <= n; j++) {
                if (line[j-1] == '#')
                    m[i][j] = -1; // 不可通过
                else if (line[j-1] == '.')
                    m[i][j] = 0;
                else if (line[j-1] == 'K') { // 起点
                    m[i][j] = 0;
                    dp[0].push_back(Node(i, j, 0, 0));
                } else if (line[j-1] == 'T') { // 终点
                    m[i][j] = k + 1;
                } else if (line[j-1] >= '1' and line[j-1] <= '9') { // key
                    m[i][j] = line[j-1] - '0';
                } else if (line[j-1] == 'S') { // 蛇
                    m[i][j] = 99;
                    snake.insert(make_pair(hash(i, j), snake_cnt++));
                }
            }
        }
/*
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                cout << setw(3) << m[i][j];
            cout << endl;
        }
        cout << endl;
*/
        // search
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < dp[i].size(); j++)
                bfs(dp[i][j]);
            dp[i].clear();
        }

        // output
        if (dp[k+1].empty())
            cout << "impossible" << endl;
        else {
            int ans = INT_MAX;
            for (int i = 0; i < dp[k+1].size(); i++)
                ans = min(ans, dp[k+1][i].step);
            cout << ans << endl;
        }
    }

    return 0;
}


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int m, n;
char M[10][11];
int vis[10][10];
int cnt[10][10];
int D[10][10];

struct Node {
    int x, y, t;
    Node() {}
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

void bfs(int s_x, int s_y, int k) {
    static int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
    memset(vis, 0, sizeof(vis));
    vis[s_x][s_y] = 1;
    ++cnt[s_x][s_y];
    
    queue<Node> q;
    q.push(Node(s_x, s_y, 0));
    while (not q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        q.pop();

        for (int i = 0; i != 8; ++i) {
            int _x = x + dir[i][0];
            int _y = y + dir[i][1];
            int _t = t + 1;
            if (_x < 0 or _x >= m or _y < 0 or _y >= n)
                continue;
            if (vis[_x][_y])
                continue;

            vis[_x][_y] = 1;
            D[_x][_y] += _t / k + (_t % k ? 1 : 0);
            ++cnt[_x][_y];
            q.push(Node(_x, _y, _t));
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        cin >> m >> n;
        memset(cnt, 0, sizeof(cnt));
        memset(D, 0, sizeof(D));
        for (int i = 0; i != m; ++i)
            cin >> M[i];

        int total = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (M[i][j] != '.') {
                    bfs(i, j, M[i][j] - '0');
                    ++total;
                }
            }
        }

        int ans = -1;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (cnt[i][j] == total and (ans == -1 or D[i][j] < ans)) {
                    ans = D[i][j];
                }
            }
        }
        cout << "Case " << cases << ": " << ans << endl;    
    }
    return 0;
}


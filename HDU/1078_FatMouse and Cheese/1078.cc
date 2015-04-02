#include <iostream>
#include <cstring>

using namespace std;
int n, k;

int m[101][101], dp[101][101];

int dfs(int x, int y) {
    static int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    if (dp[x][y] != 0)
        return dp[x][y];

    dp[x][y] = m[x][y];
    for (int i = 0; i != 4; ++i) {
        for (int j = 1; j <= k; ++j) {
            int _x = x + dir[i][0] * j;
            int _y = y + dir[i][1] * j;
            if (_x < 0 or _x >= n or _y < 0 or _y >= n)
                break;
            if (m[x][y] < m[_x][_y])
                dp[x][y] = max(dp[x][y], dfs(_x, _y) + m[x][y]);
        }
    }
    return dp[x][y];
}

int main() {
    while (cin >> n >> k and n != -1 and k != -1) {
        memset(m, 0, sizeof(m));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j)
                cin >> m[i][j];
        cout << dfs(0, 0) << endl;
    }
    return 0;
}


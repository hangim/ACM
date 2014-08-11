#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int city_num;
int adj[401][401];

int match[401];
int vis[401];

bool dfs(int u) {
    for (int v = 1; v <= city_num; v++) {
        if (not vis[v] and adj[u][v]) {
            vis[v] = 1;
            if (match[v] == -1 or dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }

    return false;
}

int hungary() {
    int ans = 0;
    memset(match, -1, sizeof(match));

    for (int u = 1; u <= city_num; u++) {
        if (match[u] == -1) {
            memset(vis, 0, sizeof(vis));
            if (dfs(u))
                ans++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        // input
        int h, w;
        cin >> h >> w;
        city_num = 0;
        int matrix[42][12];
        memset(matrix, 0, sizeof(matrix));
        for (int i = 1; i <= h; i++) {
            string line;
            cin >> line;
            for (int j = 1; j <= w; j++) {
                if (line[j-1] == '*')
                    matrix[i][j] = ++city_num;
            }
        }

        // init adj
        int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
        memset(adj, 0, sizeof(adj));
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                int now = 0;
                if ((now = matrix[i][j]) == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int next = 0;
                    if (next = matrix[i+dir[k][0]][j+dir[k][1]])
                        adj[now][next] = 1;
                }
            }
        }

        // output
        cout << city_num - hungary() << endl;
    }

    return 0;
}


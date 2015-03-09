#include <cstdio>
#include <cstring>
#include <string>

int n, m, t;
char M[8][8];

bool dfs(int x, int y, int time) {
    static int dir[4][2] = {0, 1, -1, 0, 0, -1, 1, 0};

    if (time == t)
        return false;
    
    for (int i = 0; i != 4; ++i) {
        int _x = x + dir[i][0];
        int _y = y + dir[i][1];
        
        if (M[_x][_y] == 'D') {
            if (time + 1 == t)
                return true;
            else
                continue;
        }

        if (M[_x][_y] == '.') {
            M[_x][_y] = 'X';
            if (dfs(_x, _y, time + 1))
                return true;
            M[_x][_y] = '.';
        }
    }

    return false;
}

int main() {
    while (scanf("%d%d%d", &n, &m, &t) == 3 and n + m + t) {
        memset(M, 'X', sizeof(M));
        int x, y;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", &M[i][1]);
            for (int j = 1; j <= m; ++j) {
                if (M[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
            M[i][m+1] = 'X';
        }

        if (dfs(x, y, 0))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}


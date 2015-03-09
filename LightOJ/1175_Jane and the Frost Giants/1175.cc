#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char Maze[202][202];
int Fire[202][202];
bool Vis[202][202];
int r, c;

struct Node {
    int x, y, t;

    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

bool in_maze(int x, int y) {
    return x >= 1 and x <= r and y >= 1 and y <= c;
}

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void bfs_fire(int x, int y) {
    queue<Node> q;

    Node node(x, y, 0);
    Fire[x][y] = 0;
    q.push(node);

    while (not q.empty()) {
         node = q.front();
         q.pop();

         int x = node.x;
         int y = node.y;
         int t = node.t;

         for (int i = 0; i != 4; ++i) {
            int _x = x + dir[i][0];
            int _y = y + dir[i][1];
            int _t = t + 1;
            if (in_maze(_x, _y) and Maze[_x][_y] != '#' and (Fire[_x][_y] == -1 or _t < Fire[_x][_y])) {
                Fire[_x][_y] = _t;
                q.push(Node(_x, _y, _t));
            }
         }
    }
}

int bfs_jane(int x, int y) {
    queue<Node> q;

    Node node(x, y, 0);
    Vis[x][y] = 1;
    q.push(node);

    while (not q.empty()) {
         node = q.front();
         q.pop();

         int x = node.x;
         int y = node.y;
         int t = node.t;
         
         for (int i = 0; i != 4; ++i) {
            int _x = x + dir[i][0];
            int _y = y + dir[i][1];
            int _t = t + 1;

            if (not in_maze(_x, _y))
                return _t;

            if (Vis[_x][_y])
                continue;
    
            if (Maze[_x][_y] != '#' and _t < Fire[_x][_y]) {
                Vis[_x][_y] = 1;
                q.push(Node(_x, _y, _t));
            }
         }
    }

    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; ++cases) {
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; ++i) {
            scanf("%s", &Maze[i][1]);
        }

        int jane_x, jane_y, fire_x, fire_y;
        memset(Fire, -1, sizeof(Fire));
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (Maze[i][j] == 'J') {
                    jane_x = i;
                    jane_y = j;
                } else if (Maze[i][j] == 'F') {
                    fire_x = i;
                    fire_y = j;
                    bfs_fire(fire_x, fire_y);
                }
            }
        }

        memset(Vis, 0, sizeof(Vis));
        int ans = bfs_jane(jane_x, jane_y);

        printf("Case %d: ", cases);
        if (ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}


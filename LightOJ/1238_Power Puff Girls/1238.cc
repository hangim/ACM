#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

struct Node {
    int x, y;

    Node() {}
    Node(int _x, int _y) : x(_x), y(_y) {}
};

const int INF = 1 << 20;
char M[22][22];
int D[22][22];

int bfs(int x, int y) {
    static int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

    int ans = 0;

    D[x][y] = 0;
    queue<Node> q;
    q.push(Node(x, y));

    while (not q.empty()) {
        Node node = q.front();
        q.pop();

        for (int i = 0; i != 4; ++i) {
            int _x = node.x + dir[i][0];
            int _y = node.y + dir[i][1];

            if (D[_x][_y] != INF)
                continue;
            int _t = D[node.x][node.y] + 1;

            char c = M[_x][_y];
            switch (c) {
            case 'a' : case 'b': case 'c': 
                ans = max(ans, _t);
            case '.':
                D[_x][_y] = _t;
                q.push(Node(_x, _y));
            }
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        memset(M, '#', sizeof(M));

        int m, n;
        cin >> m >> n;

        int x, y;

        for (int i = 1; i <= m; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j != str.length(); ++j) {
                D[i][j+1] = INF;
                M[i][j+1] = str[j];
                if (str[j] == 'h') {
                    x = i;
                    y = j + 1;
                }
            }
        }

        cout << "Case " << cases << ": " << bfs(x, y) << endl;
    }

    return 0;
}


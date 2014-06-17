#include <iostream>
#include <cstring>

using namespace std;

int visited[1001];
int road[1001][1001];

void dfs(int n, int now) {
    visited[now] = 1;
    for (int i = 1; i <= n; i++) {
        if (i != now and road[now][i] and visited[i] == 0) {
            dfs(n, i);
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0)
            break;
        memset(visited, 0, sizeof(visited));
        memset(road, 0, sizeof(road));

        int pos1, pos2;
        for (int i = 0; i < m; i++) {
            cin >> pos1 >> pos2;
            road[pos1][pos2] = road[pos2][pos1] = 1;
        }

        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(n, i);
                c++;
            }
        }

        cout << c - 1 << endl;
    }

    return 0;
}

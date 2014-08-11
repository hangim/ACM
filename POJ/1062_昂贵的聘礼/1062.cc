#include <iostream>
#include <queue>

using namespace std;

const int INF = 1 << 29;

int n, m;
int rank[101];
int cost[101][101];

struct Node {
    int x;
    int d;

    bool operator < (const struct Node &o) const {
        return this->d > o.d;
    }
};

int dijkstra(int min_rank, int max_rank) {
    int d[101], vis[101];
    for (int i = 0; i <= n; i++) {
        d[i] = INF;
        vis[i] = 0;
    }
    d[0] = 0;

    priority_queue<struct Node> q;
    struct Node node = {0, d[0]};
    q.push(node);

    while (not q.empty()) {
        node = q.top();
        q.pop();
        if (node.x == 1)
            return node.d;
        if (vis[node.x])
            continue;
        vis[node.x] = 1;

        for (int i = 1; i <= n; i++) {
            if (rank[i] < min_rank or rank[i] > max_rank)
                continue;
            if (d[i] > d[node.x] + cost[node.x][i]) {
                d[i] = d[node.x] + cost[node.x][i];
                struct Node tmp = {i, d[i]};
                q.push(tmp);
            }
        }
    }

    return INF;
}

int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++)
            cost[i][j] = INF;
    }

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> cost[0][i] >> rank[i] >> x;
        for (int j = 0; j < x; j++) {
            int t;
            cin >> t;
            cin >> cost[t][i];
        }
    }

    int ans = INF;
    for (int i = rank[1]; i <= rank[1] + m; i++)
        ans = min(ans, dijkstra(i - m, i));

    cout << ans << endl;

    return 0;
}


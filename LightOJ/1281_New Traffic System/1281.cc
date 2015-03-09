#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge {
    int u, w, cnt;
    Edge() {}
    Edge(int u, int w, int cnt) {
        this->u = u;
        this->w = w;
        this->cnt = cnt;
    }
    bool operator < (const Edge &o) const {
        return w > o.w;
    }
} Node;

int n, m, k, d;
vector<Edge> e[10001];

int bfs() {
    priority_queue<Node> q;
    q.push(Node(0, 0, 0));

    while (not q.empty()) {
        int u = q.top().u;
        int w = q.top().w;
        int cnt = q.top().cnt;
        q.pop();

        if (u == n - 1)
            return w;

        for (int i = 0; i != e[u].size(); ++i) {
            if (cnt + e[u][i].cnt > d)
                continue;
            q.push(Node(e[u][i].u, w + e[u][i].w, cnt + e[u][i].cnt));
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        for (int i = 0; i <= 10000; ++i)
            e[i].clear();

        cin >> n >> m >> k >> d;
        for (int i = 0; i != m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back(Edge(v, w, 0));
        }
        for (int i = 0; i != k; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back(Edge(v, w, 1));
        }

        int ans = bfs();

        cout << "Case " << cases << ": ";
        if (ans != -1)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}


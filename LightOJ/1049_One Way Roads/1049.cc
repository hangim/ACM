#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int v, w;
    Edge() {}
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

vector<Edge> e[101];

int dfs(int u, int p) {
    for (int i = 0; i != 2; ++i) {
        int &v = e[u][i].v, &w = e[u][i].w;
        if (v == p)
            continue;

        if (v == 1)
            return w;
        else
            return w + dfs(v, u);
    }
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        for (int i = 0; i <= 100; ++i)
            e[i].clear();

        int n;
        cin >> n;
        for (int i = 0; i != n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            e[a].push_back(Edge(b, 0));
            e[b].push_back(Edge(a, c));
        }

        int ans1 = dfs(1, e[1][1].v);
        int ans2 = dfs(1, e[1][0].v);

        cout << "Case " << cases << ": " << min(ans1, ans2) << endl;
    }

    return 0;
}


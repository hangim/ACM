#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

const int INF = 1 << 20;
int n, m;
vector<Edge> e;
int D[101];

void bellman_ford() {
    for (int i = 1; i <= n; ++i)
        D[i] = INF;

    D[1] = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != e.size(); ++j) {
            int &u = e[j].u, &v = e[j].v, &w = e[j].w;
            D[v] = min(D[u] + w, D[v]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int cases = 1; cases <= t; ++cases) {
        e.clear();
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            e.push_back(Edge(u, v, w));
            e.push_back(Edge(v, u, w));
        }

        bellman_ford();

        cout << "Case " << cases << ": ";
        if (D[n] != INF)
            cout << D[n] << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}


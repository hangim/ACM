#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
    Edge() {}
    Edge(int _u, int _v) : u(_u), v(_v) {}
};

const int INF = 1 << 20;
int n;
int D1[100], D2[100];
vector<Edge> e;

void bellman_ford(int _u, int *D) {
    for (int i = 0; i != n; ++i)
        D[i] = INF;
    D[_u] = 0;

    for (int i = 0; i != n-1; ++i) {
        for (int j = 0; j != e.size(); ++j) {
            int &u = e[j].u;
            int &v = e[j].v;
            D[v] = min(D[u] + 1, D[v]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        cin >> n;

        int r;
        cin >> r;
        e.clear();
        for (int i = 0; i != r; ++i) {
            int u, v;
            cin >> u >> v;
            e.push_back(Edge(u, v));
            e.push_back(Edge(v, u));
        }

        int s, d;
        cin >> s >> d;
        bellman_ford(s, D1);
        bellman_ford(d, D2);

        int ans = 0;
        for (int i = 0; i != n; ++i)
            ans = max(D1[i] + D2[i], ans);

        cout << "Case " << cases << ": " << ans << endl;
    }

    return 0;
}


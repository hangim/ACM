#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, t;
    Edge(int _u, int _v, int _t) : u(_u), v(_v), t(_t) {}
};

vector<Edge> E;

int D1[1010], D2[1010];

int bellman_ford(int n, int x) {
    for (int i = 1; i <= n; ++i)
        D1[i] = D2[i] = INF;
    D1[x] = D2[x] = 0;

    for (int i = 1; i != n; ++i) {
        for (int j = 0; j != E.size(); ++j) {
            int &u = E[j].u, &v = E[j].v, &t = E[j].t;
            D1[v] = min(D1[v], D1[u] + t);
            D2[u] = min(D2[u], D2[v] + t);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i != x and ans < D1[i] + D2[i])
            ans = D1[i] + D2[i];
    }
    return ans;
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i != m; ++i) {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        E.push_back(Edge(u, v, t));
    }
    printf("%d\n", bellman_ford(n, x));
    return 0;
}


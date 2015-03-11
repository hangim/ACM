#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<Edge> E;

int D[1010];

int bellman_ford(int n) {
    for (int i = 1; i <= n; ++i) {
        D[i] = 0;
    }
    D[1] = INF;
    
    bool flag = true;
    for (int i = 1; flag and i != n; ++i) {
        flag = false;
        for (int j = 0; j != E.size(); ++j) {
            int &u = E[j].u, &v = E[j].v, &w = E[j].w;
            int tmp = min(D[u], w);
            if (D[v] < tmp) {
                D[v] = tmp;
                flag = true;
            }
        }
    }
    return D[n];
}

int main() {
    int k;
    scanf("%d", &k);
    for (int cases = 1; cases <= k; ++cases) {
        int n, m;
        scanf("%d %d", &n, &m);
        E.clear();
        for (int i = 0; i != m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            E.push_back(Edge(u, v, w));
            E.push_back(Edge(v, u, w));
        }
        printf("Scenario #%d:\n", cases);
        printf("%d\n\n", bellman_ford(n));
    }

    return 0;
}


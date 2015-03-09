#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct Edge {
    int v, c;
    Edge(int _v, int _c) : v(_v), c(_c) {}
};

int n;
vector<Edge> e[50];
const int INF = 1e9;
int D[50], vis[50];

int prim(int u) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i != n; ++i)
        D[i] = INF;
    D[u] = 0;

    int ans = 0;
    while (u != -1) {
        vis[u] = 1;
        ans += D[u];

        for (int i = 0; i != e[u].size(); ++i) {
            int &v = e[u][i].v, &c = e[u][i].c;
            D[v] = min(D[v], c);
        }

        u = -1;
        int tmp = INF;
        for (int i = 0; i != n; ++i) {
            if (vis[i] == 0 and D[i] < tmp) {
                u = i;
                tmp = D[i];
            }
        }
    }

    for (int i = 0; i != n; ++i) {
        if (D[i] == INF)
            return -1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        for (int i = 0; i != 50; ++i)
            e[i].clear();

        int m;
        cin >> m;

        n = 0;
        map<string, int> city_map;
        for (int i = 0; i != m; ++i) {
            string city1, city2;
            int cost;
            cin >> city1 >> city2 >> cost;
            int u, v;
            if (city_map.find(city1) != city_map.end())
                u = city_map[city1];
            else
                u = city_map[city1] = n++;
            if (city_map.find(city2) != city_map.end())
                v = city_map[city2];
            else
                v = city_map[city2] = n++;
            e[u].push_back(Edge(v, cost));
            e[v].push_back(Edge(u, cost));
        }
        
        int ans = prim(0);

        cout << "Case " << cases << ": ";
        if (ans != -1)
            cout << ans << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}


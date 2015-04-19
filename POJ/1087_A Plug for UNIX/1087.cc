#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 410;
int g[MAXN][MAXN], path[MAXN], flow[MAXN];
int N;
const int src = 0, dst = 1;
const int INF = 1e9;

int bfs() {
    queue<int> q;
    q.push(src);
    memset(path, -1, sizeof(path));
    flow[src] = INF;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dst)
            break;
        for (int v = 1; v <= N; ++v) {
            if (path[v] == -1 and g[u][v]) {
                flow[v] = min(flow[u], g[u][v]);
                path[v] = u;
                q.push(v);
            }
        }
    }
    return path[dst] == -1 ? -1 : flow[dst];
}

int Edmonds_Karp() {
    int max_flow = 0, d;
    while ((d = bfs()) != -1) {
        max_flow += d;
        int now = dst;
        while (now != src) {
            int pre = path[now];
            g[pre][now] -= d;
            g[now][pre] += d;
            now = pre;
        }
    }
    return max_flow;
}

int main() {
    int n, m, k;
    map<string, int> Map;

    N = 1;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        string str;
        cin >> str;
        Map[str] = ++N;
        g[src][N] = 1;
    }

    cin >> m;
    for (int i = 0; i != m; ++i) {
        string str1, str2;
        cin >> str1 >> str2;
        if (Map.find(str2) == Map.end())
            Map[str2] = ++N;
        int u = Map[str2];
        ++g[u][dst];
    }

    cin >> k;
    for (int i = 0; i != k; ++i) {
        string str1, str2;
        cin >> str1 >> str2;
        if (Map.find(str1) == Map.end())
            Map[str1] = ++N;
        if (Map.find(str2) == Map.end())
            Map[str2] = ++N;
        int v = Map[str1], u = Map[str2];
        g[u][v] = INF;
    }

    cout << m - Edmonds_Karp() << endl;
    return 0;
}


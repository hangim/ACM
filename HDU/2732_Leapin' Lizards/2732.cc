#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2200;
const int MAXM = 200020;
const int INF = 0x3FFFFFFF;

struct Node {
    int u, v, c, next;
} edge[MAXM];

int N, tol, head[MAXN], src, dst, dep[MAXN], gap[MAXN];

void init(int n) {
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int c) {
    edge[tol] = {u, v, c, head[u]};
    head[u] = tol++;
    edge[tol] = {v, u, 0, head[v]};
    head[v] = tol++;
}

void bfs() {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));

    ++gap[dep[dst] = 0];
    queue<int> q;
    q.push(dst);

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (dep[edge[i].v] == -1) {
                ++gap[dep[edge[i].v] = dep[u] + 1];
                q.push(edge[i].v);
            }
        }
    }
}

int sap() {
    bfs();
    int max_flow = 0, cur[MAXN], path[MAXN], top = 0;
    memcpy(cur, head, sizeof(head));

    int u = src;
    while (dep[src] < N) {
        if (u == dst) {
            int res = INF, inser;
            for (int i = 0; i != top; ++i) {
                if (res > edge[path[i]].c) {
                    res = edge[path[i]].c;
                    inser = i;
                }
            }
            for (int i = 0; i != top; ++i) {
                edge[path[i]].c -= res;
                edge[path[i]^1].c += res;
            }
            max_flow += res;
            u = edge[path[top = inser]].u;
        }

        if (gap[dep[u] - 1] == 0)
            break;

        bool need_relabel = true;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            if (dep[u] == dep[edge[i].v] + 1 and edge[i].c) {
                cur[u] = i;
                u = edge[path[top++] = i].v;
                need_relabel = false;
                break;
            }
        }

        if (need_relabel) {
            --gap[dep[u]];
            dep[u] = N;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                if (dep[u] > dep[edge[i].v] + 1 and edge[i].c) {
                    cur[u] = i;
                    dep[u] = dep[edge[i].v] + 1;
                }
            }
            ++gap[dep[u]];

            if (u != src)
                u = edge[path[--top]].u;
        }
    }

    return max_flow;
}

char g1[22][22], g2[22][22];

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n, m, d;
        cin >> n >> d;
        for (int i = 0; i != n; ++i)
            cin >> g1[i];
        for (int i = 0 ; i != n; ++i)
            cin >> g2[i];
        m = strlen(g1[0]);

        init(2 * n * m + 2);
        src = 0, dst = 2 * n * m + 1;
        
        int cnt = 0;

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (g1[i][j] == '0')
                    continue;
                
                addedge(i*m + j+1, i*m + j+1 + n*m, g1[i][j] - '0');
                if (g2[i][j] == 'L') {
                    addedge(src, i*m + j+1, 1);
                    ++cnt;
                }
                if (i - d < 0 or i + d >= n or j - d < 0 or j + d >= m)
                    addedge(i*m + j+1 + n*m, dst, INF);
                for (int x = i - d; x <= i + d; ++x) {
                    for (int y = j - d; y <= j + d; ++y) {
                        if (x == i and y == j)
                            continue;
                        if (x >= 0 and y >= 0 and x < n and y < m
                            and abs(i - x) + abs(j - y) <= d
                            and g1[x][y] != '0') {
                            addedge(i*m + j+1 + n*m, x*m + y+1, INF);
                        }
                    }
                }
            }
        }

        int ans = cnt - sap();
        cout << "Case #" << cases << ": ";
        if (ans == 0)
            cout << "no lizard was left behind." << endl;
        else if (ans == 1)
            cout << ans << " lizard was left behind." << endl;
        else
            cout << ans << " lizards were left behind." << endl;

    }
    return 0;
}


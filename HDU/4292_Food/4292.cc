#include <bits/stdc++.h>

using namespace std;

const int MAXN = 810;
const int MAXM = 161210;
const int INF = 0x3FFFFFFF;

struct Node {
    int u, v, c;
    int next;
} edge[MAXM];

int n, tol;
int head[MAXN], dep[MAXN], gap[MAXN];

void init(int _n) {
    n = _n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int c) {
    edge[tol] = {u, v, c, head[u]};
    head[u] = tol++;
    edge[tol] = {v, u, 0, head[v]};
    head[v] = tol++;
}

void bfs() {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));

    queue<int> q;
    ++gap[dep[n] = 0];
    q.push(n);
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dep[v] == -1) {
                ++gap[dep[v] = dep[u] + 1];
                q.push(v);
            }
        }
    }
}

int SAP() {
    int max_flow = 0;
    bfs();

    int cur[MAXN];
    memcpy(cur, head, sizeof(head));
    int path[MAXN], top = 0;

    int u = 0;
    while (dep[0] < n) {
        if (u == n) {
            int res = INF, inser;
            for (int i = 0; i != top; ++i) {
                if (edge[path[i]].c < res) {
                    res = edge[path[i]].c;
                    inser = i;
                }
            }
            for (int i = 0; i != top; ++i) {
                edge[path[i]].c -= res;
                edge[path[i]^1].c += res;
            }
            max_flow += res;
            top = inser;
            u = edge[path[top]].u;
        }
        if (u != n and gap[dep[u]-1] == 0)
            break;

        bool need_relabel = true;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].c and dep[u] == dep[v] + 1) {
                cur[u] = i;
                path[top++] = i;
                u = v;
                need_relabel = false;
                break;
            }
        }
        
        if (need_relabel) {
            --gap[dep[u]];
            dep[u] = n;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].v;
                if (edge[i].c and dep[u] > dep[v] + 1) {
                    dep[u] = dep[v] + 1;
                    cur[u] = i;
                }
            }
            ++gap[dep[u]];
            if (u != 0)
                u = edge[path[--top]].u;
        }
    }
    return max_flow;
}

int main() {
    int N, F, D;
    while (scanf("%d%d%d", &N, &F, &D) != EOF) {
        init(F + 2 * N + D + 1);

        int u, v, c;
        char str[210];
        for (int i = 1; i <= F; ++i) {
            scanf("%d", &c);
            add_edge(0, i, c);
        }
        for (int i = 1; i <= N; ++i) {
            add_edge(i+F, i+F+N, 1);
        }
        for (int i = 1; i <= D; ++i) {
            scanf("%d", &c);
            add_edge(i+F+2*N, n, c);
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%s", str+1);
            for (int j = 1; j <= F; ++j) {
                if (str[j] == 'Y')
                    add_edge(j, i+F, 1);
            }
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%s", str+1);
            for (int j = 1; j <= F; ++j) {
                if (str[j] == 'Y')
                    add_edge(i+F+N, j+F+2*N, 1);
            }
        }
        printf("%d\n", SAP());
    }
    return 0;
}


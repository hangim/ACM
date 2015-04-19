#include <bits/stdc++.h>

using namespace std;

const int MAXN = 410;
const int MAXM = 80500;
const int INF = 0x3FFFFFFF;

int src, dst, n, tol;
int head[MAXN], dep[MAXN], gap[MAXN];

struct Node {
    int u, v, c, next;
} edge[MAXM];

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
    ++gap[dep[dst] = 0];
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
    while (dep[src] < n) {
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
        
        if (gap[dep[u]-1] == 0)
            break;
        
        bool need_relabel = true;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            if (edge[i].c and dep[u] == dep[edge[i].v] + 1) {
                path[top++] = cur[u] = i;
                u = edge[i].v;
                need_relabel = false;
                break;
            }
        }

        if (need_relabel) {
            --gap[dep[u]];
            dep[u] = n;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                if (edge[i].c and dep[u] > dep[edge[i].v] + 1) {
                    dep[u] = dep[edge[i].v] + 1;
                    cur[u] = i;
                }
            }
            ++gap[dep[u]];
            if (u != src) {
                u = edge[path[--top]].u;
            }
        }
    }

    return max_flow;
}

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF) {
        init(2 * N);

        scanf("%d%d", &src, &dst);
        dst += N;

        int u, v, c;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &c);
            add_edge(i, i+N, c);
        }
        for (int i = 1; i <= M; ++i) {
            scanf("%d%d", &u, &v);
            add_edge(u+N, v, INF);
            add_edge(v+N, u, INF);
        }
        printf("%d\n", sap());
    }

    return 0;
}


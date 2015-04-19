/* SAP 最大流模板 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010; // 点数最大值
const int MAXM = 400010; // 边数最大值
const int INF = 0x3FFFFFFF;

struct Node {
    int from, to, next;
    int cap;
} edge[MAXM];

int tol;        // 边总数
int head[MAXN];
int dep[MAXN];  // 高度函数
int gap[MAXN];  // gap[x] = y : 说明残留网络中dep[i] == x 的个数为 y

int n;

void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w) {
    edge[tol].from = u;
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    head[u] = tol++;

/* 有向图反向边
    edge[tol].from = v;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
*/
}

/* 反向BFS建立高度函数 */
void BFS(int src, int dst) {
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));

    queue<int> q;
    q.push(dst);

    ++gap[dep[dst] = 0];

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                ++gap[dep[v]];
                q.push(v);
            }
        }
    }
}

int SAP(int src, int dst) {
    BFS(src, dst);

    int max_flow = 0;
    int cur[MAXN];      // 记录允许弧
    memcpy(cur, head, sizeof(head));
    int path[MAXN], top = 0;   // 记录增广路

    int u = src;
    while (dep[src] < n) {  // dep[src]最大值n-1
        if (u == dst) {     // 找到一条增广路
            int res = INF;  // 残留容量
            int inser;
            for (int i = 0; i < top; ++i) {
                if (res > edge[path[i]].cap) {
                    res = edge[path[i]].cap;
                    inser = i;
                }
            }
            for (int i = 0; i < top; ++i) {
                edge[path[i]].cap -= res;
                edge[path[i]^1].cap += res; // 反向边
            }
            max_flow += res;
            top = inser;
            u = edge[path[top]].from; // 回溯
        }

        if (u != dst and gap[dep[u]-1] == 0)
            break; // 出现断层, 无增广路

        // 从当前点开始寻找允许弧
        bool flag = false;
        for (int i = cur[u]; i != -1; i = edge[i].next) {
            if (edge[i].cap and dep[u] == dep[edge[i].to] + 1) {
                cur[u] = i;
                path[top++] = i;
                u = edge[i].to;
                flag = true;
                break;
            }
        }

        if (not flag) {
            // 没有找到允许弧, 改变u的标号
            // 寻找 min{dep[v]}, 存在边(u, v)
            // dep[u] = dep[v] + 1, &v = edge[i].to
            --gap[dep[u]];
            dep[u] = n + 1;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                if (edge[i].cap and dep[u] > dep[edge[i].to] + 1) {
                    dep[u] = dep[edge[i].to] + 1;
                    cur[u] = i;
                }
            }
            ++gap[dep[u]];
            if (u != src)
                u = edge[path[--top]].from; // 回溯
        }
    }

    return max_flow;
}

int main() {
    int src, dst;
    int m;
    int u, v, z;
    int T;
    scanf("%d", &T);

    while (T--) {
        init();
        scanf("%d%d", &n, &m);
        int minx = 10000000;
        int maxx = -10000000;
        int x, y;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            if (minx > x) {
                minx = x;
                src = i; // 源点
            }
            if (maxx < x) {
                maxx = x;
                dst = i; // 汇点
            }
        }

        while (m--) {
            scanf("%d%d%d", &u, &v, &z);
            addedge(u, v, z);
            addedge(v, u, z); // 无向图
        }

        int ans = SAP(src, dst);
        printf("%d\n", ans);
    }
}


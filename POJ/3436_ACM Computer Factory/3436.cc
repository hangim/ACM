#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 110;
const int INF = 0x3FFFFFFF;
int g[MAXN][MAXN];
int path[MAXN], flow[MAXN], src, dst;
int n;

int bfs() {
    queue<int> q;
    memset(path, -1, sizeof(path));
    path[src] = 0;
    flow[src] = INF;
    q.push(src);
    while (not q.empty()) {
        int t = q.front();
        q.pop();
        if (t == dst)
            break;
        for (int i = 0; i <= n; ++i) {
            if (i != src and path[i] == -1 and g[t][i]) {
                flow[i] = min(flow[t], g[t][i]);
                q.push(i);
                path[i] = t;
            }
        }
    }
    if (path[dst] == -1)
        return -1;
    return flow[dst];
}

int Edmonds_Karp() {
    int max_flow = 0;
    int step, now, pre;
    while ((step = bfs()) != -1) {
        max_flow += step;
        now = dst;
        while (now != src) {
            pre = path[now];
            g[pre][now] -= step;
            g[now][pre] += step;
            now = pre;
        }
    }
    return max_flow;
}

int backup[MAXN][MAXN];
int in[MAXN][22];
int Line[MAXN][3];

int main() {
    int P, N;
    while (cin >> P >> N) {
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j != 2 * P + 1; ++j)
                cin >> in[i][j];
        }
        for (int i = 1; i <= N; ++i) { // 拆点
            g[i][i+N] = in[i][0];
        }
        src = 0;
        dst = n = 2 * N + 1;
        for (int i = 1; i <= N; ++i) { // 建图
            bool flag_s = true, flag_t = true;
            for (int j = 0; j != P; ++j) {
                if (in[i][j+1] == 1) // 不能有1
                    flag_s = false;
                if (in[i][j+1+P] == 0) // 不能有0
                    flag_t = false;
            }
            if (flag_s)
                g[src][i] = INF;
            if (flag_t)
                g[i+N][dst] = INF;
            for (int j = 1; j <= N; ++j) {
                if (i == j)
                    continue;
                bool flag = true;
                for (int k = 0; k != P; ++k) {
                    if ((in[i][k+1+P] == 0 and in[j][k+1] == 1)
                        or (in[i][k+1+P] == 1 and in[j][k+1] == 0)) { // 不能生产后不使用
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    g[i+N][j] = in[i][0];
            }
        }
        
        memcpy(backup, g, sizeof(g));
        cout << Edmonds_Karp() << " ";
        int tol = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (g[i+N][j] < backup[i+N][j]) {
                    Line[tol][0] = i;
                    Line[tol][1] = j;
                    Line[tol][2] = backup[i+N][j] - g[i+N][j];
                    ++tol;
                }
            }
        }
        cout << tol << endl;
        for (int i = 0; i != tol; ++i)
            cout << Line[i][0] << " " << Line[i][1] << " "
                 << Line[i][2] << endl;
    }
    return 0;
}


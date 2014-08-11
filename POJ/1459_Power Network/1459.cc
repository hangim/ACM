#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <cstdio>

using namespace std;

int n, np, nc, m;
int cap[102][102]; // capacity 容量
int flow[102]; // 残余容量
int pre[102]; // 前驱

int bfs(int src, int dst) {
    memset(pre, -1, sizeof(pre));
    
    memset(flow, 0, sizeof(flow));
    flow[src] = INT_MAX;
    
    queue<int> q;
    q.push(src);

    while (not q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == dst)
            return flow[x];

        for (int i = 1; i <= n+1; i++) {
            // i != src
            if (pre[i] == -1 and cap[x][i] > 0) {
                flow[i] = min(flow[x], cap[x][i]);
                pre[i] = x;
                q.push(i);
            }
        }
    }

    return 0;
}

int ek(int src, int dst) {
    // Edmonds-Karp
    int sum_flow = 0;
    int var;
    while (var = bfs(src, dst)) {
        int q = dst;
        while (q != src) {
            int p = pre[q];
            cap[p][q] -= var;
            cap[q][p] += var;
            q = p;
        }
        sum_flow += var;
    }
    return sum_flow;
}

int main() {
    while (cin >> n >> np >> nc >> m) {
        memset(cap, 0, sizeof(cap));
        for (int i = 0; i < m; i++) {
            int u, v, z;
            scanf(" (%d,%d)%d", &u, &v, &z);
            cap[u+1][v+1] = z;
        }
        for (int i = 0; i < np; i++) {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[0][u+1] = z;
            
        }
        for (int i = 0; i < nc; i++) {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[u+1][n+1] = z;
        }

        cout << ek(0, n+1) << endl;
    }
    
    return 0;
}


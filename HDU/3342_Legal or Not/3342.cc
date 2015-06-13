#include <bits/stdc++.h>

using namespace std;

int N, M;
int edge[110][2];
int dist[110];

bool bellman_ford() {
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < N; ++i) {
        bool flag = true;
        for (int j = 0; j < M; ++j) {
            int u = edge[j][0], v = edge[j][1];
            if (dist[u] < dist[v] + 1) {
                dist[u] = dist[v] + 1;
                flag = false;
            }
        }
        if (flag)
            return true;
    }
    return false;
}

int main() {
    while (cin >> N >> M and N + M) {
        for (int i = 0; i != M; ++i) {
            cin >> edge[i][0] >> edge[i][1];
        }
        cout << (bellman_ford() ? "YES" : "NO") << endl;
    }
    return 0;
}


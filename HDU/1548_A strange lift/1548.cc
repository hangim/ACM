#include <bits/stdc++.h>

using namespace std;

int num[210], vis[210], dist[210];

int main() {
    int N, A, B;
    while (cin >> N and N) {
        memset(vis, 0, sizeof(vis));

        cin >> A >> B;
        for (int i = 1; i <= N; ++i)
            cin >> num[i];

        queue<int> q;
        q.push(A);
        dist[A] = 0;
        vis[A] = 1;
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            int Up = u + num[u];
            int Down = u - num[u];
            if (Up <= N and vis[Up] == 0) {
                dist[Up] = dist[u] + 1;
                q.push(Up);
                vis[Up] = 1;
            }
            if (Down >= 1 and vis[Down] == 0) {
                dist[Down] = dist[u] + 1;
                q.push(Down);
                vis[Down] = 1;
            }
        }

        if (vis[B] == 0)
            cout << -1 << endl;
        else
            cout << dist[B] << endl;
    }
    return 0;
}


#include <iostream>

using namespace std;

const int INF = 1 << 29;
int n, m, w;
int d[501];

struct Edge {
    int u, v;
    int c;
} e[5200];

bool bellMan_ford() {
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    
    d[1] = 0;
    
    for (int i = 0; i < n; i++) {
        bool flag = true;

        for (int j = 0; j < 2 * m + w; j++) {
            int &u = e[j].u, &v = e[j].v, &c = e[j].c;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                flag = false;
            }
        }

        if (flag)
            return true;
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> w;
        for (int i = 0; i < m + w; i++)
            cin >> e[i].u >> e[i].v >> e[i].c;
        for (int i = m; i < m + w; i++)
            e[i].c = -e[i].c;
        for (int i = m + w; i < 2 * m + w; i++)
            e[i].v = e[i-m-w].u, e[i].u = e[i-m-w].v, e[i].c = e[i-m-w].c;

        if (bellMan_ford())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}


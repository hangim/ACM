#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

struct Vertex {
    int x, y;
} v[1001];

int n;
double d[1001];
int p[1001];
int vis[1001];
const double INF = 1e9;

double dist(int a, int b) {
    return sqrt(pow(v[a].x - v[b].x, 2) + pow(v[a].y - v[b].y, 2));
}

int find() {
    int v = 0;
    for (int i = 1; i <= n; i++) {
        if (not vis[i] and d[i] < d[v])
            v = i;
    }
    return v;
}

double func() {
    for (int i = 0; i <= n; i++)
        d[i] = INF;
    memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));

    d[1] = 0;
    int x;
    while (x = find()) {
        if (x == 2)
            break;
        vis[x] = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;
            double tmp = dist(x, i);
            if (tmp < d[i]) {
                d[i] = tmp;
                p[i] = x;
            }
        }
    }

    double ans = d[2];
    int q = p[2];
    while (q) {
        ans = max(ans, d[q]);
        q = p[q];
    }
    return ans;
}

int main() {
    int k = 1;
    while (cin >> n and n) {
        for (int i = 1; i <= n; i++)
            cin >> v[i].x >> v[i].y;
        cout << "Scenario #" << k++ << endl
             << "Frog Distance = " << setprecision(3) << fixed
             << func() << endl << endl;
    }
    
    return 0;
}


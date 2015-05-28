#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <iomanip>

using namespace std;

int n;
int np, nl;
double p[100][2], line[100][4];
double adj[100][100];

double cross(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool seg(int i, int j) {
    if (p[i][0] == p[j][0])
        return true;
    double x1 = p[i][0], y1 = p[i][1], x2 = p[j][0], y2 = p[j][1];
    for (int k = 0; k != nl; ++k) {
        double x3 = line[k][0], y3 = line[k][1], x4 = line[k][2], y4 = line[k][3];
        if (      cross(x3 - x1, y3 - y1, x2 - x1, y2 - y1)
                * cross(x4 - x1, y4 - y1, x2 - x1, y2 - y1) < 0
            and   cross(x1 - x4, y1 - y4, x3 - x4, y3 - y4)
                * cross(x2 - x4, y2 - y4, x3 - x4, y3 - y4) < 0) {
            return true;
        }
    }
    return false;
}

double dist[100];
int vis[100];

double spfa(int s, int t) {
    for (int i = 0; i != np; ++i)
        dist[i] = 1e9, vis[i] = 0;
    dist[s] = 0, vis[s] = 1;

    queue<int> q;
    q.push(s);

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i != np; ++i) {
            if (adj[u][i] != 0 and dist[u] + adj[u][i] < dist[i]) {
                dist[i] = dist[u] + adj[u][i];
                if (vis[i] == 0) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        vis[u] = 0;
    }

    return dist[t];
}

int main() {
    while (cin >> n and n != -1) {
        p[0][0] = 0,  p[0][1] = 5;
        p[1][0] = 10, p[1][1] = 5;
        np = 2, nl = 0;
        for (int i = 0; i != n; ++i) {
            double x, a, b, c, d;
            cin >> x >> a >> b >> c >> d;

            p[np][0] = x, p[np][1] = a; ++np;
            p[np][0] = x, p[np][1] = b; ++np;
            p[np][0] = x, p[np][1] = c; ++np;
            p[np][0] = x, p[np][1] = d; ++np;

            line[nl][0] = x, line[nl][1] = 0, line[nl][2] = x, line[nl][3] = a;  ++nl;
            line[nl][0] = x, line[nl][1] = b, line[nl][2] = x, line[nl][3] = c;  ++nl;
            line[nl][0] = x, line[nl][1] = d, line[nl][2] = x, line[nl][3] = 10; ++nl;
        }

        memset(adj, 0, sizeof(adj));
        for (int i = 0; i != np; ++i) {
            for (int j = i; j != np; ++j) {
                if (not seg(i, j))
                    adj[i][j] = adj[j][i] = hypot(p[i][0] - p[j][0], p[i][1] - p[j][1]);
            }
        }

        cout << setprecision(2) << fixed << spfa(0, 1) << endl;
    }

    return 0;
}


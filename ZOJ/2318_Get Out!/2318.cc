#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Edge {
    int u;
    int v;
    double w;

    Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
};

vector<Edge> e;

double x[301], y[301], r[301], l[301];
double d[301];

bool bellman_ford(int n) {
    for (int i = 1; i <= n; i++)
        d[i] = 0;

    for (int k = 0; k <= n; ++k) {
        bool flag = true;
        
        for (int i = 0; i != e.size(); ++i) {
            int &u = e[i].u;
            int &v = e[i].v;
            double &w = e[i].w;
            if (d[v] > d[u] + w + 1e-9) { // 1e-9 !!!
                d[v] = d[u] + w;
                flag = false;
            }
        }

        if (flag)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        e.clear();
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i] >> r[i];
        }
        
        double x0, y0, r0;
        cin >> x0 >> y0 >> r0;
        for (int i = 1; i <= n; i++) {
            x[i] -= x0;
            y[i] -= y0;
            r[i] += r0;
            l[i] = hypot(x[i], y[i]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (hypot(x[i] - x[j], y[i] - y[j]) + 1e-9 < r[i] + r[j]) { // 1e-9 !!!
                    double w = (x[i] * x[j] + y[i] * y[j]) / (l[i] * l[j]);
                    w = acos(w);
                    if (x[i] * y[j] - x[j] * y[i] < 0)
                        w = -w; // 逆时针
                    e.push_back(Edge(i, j, w));
                    e.push_back(Edge(j, i, -w));
                }
            }
        }

        if (bellman_ford(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        if (t)
            cout << endl;
    }

    return 0;
}


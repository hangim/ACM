#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
    int a, b;
    double r1, c1;
    double r2, c2;
} e[101];

int n, m, s;
double v;
double d[101];

bool bellman_ford() {
    memset(d, 0, sizeof(d));
    d[s] = v;
    bool flag;
    for (int j = 0; j < n; j++) {
        flag = false;
        for (int i = 0; i < m; i++) {
            double tmp = (d[e[i].a] - e[i].c1) * e[i].r1;
            if (d[e[i].b] < tmp) {
                d[e[i].b] = tmp;
                flag = true;
            }

            tmp = (d[e[i].b] - e[i].c2) * e[i].r2;
            if (d[e[i].a] < tmp) {
                d[e[i].a] = tmp;
                flag = true;
            }
        }

        if (flag == false)
            break;
    }

    return flag;
}

int main() {
    cin >> n >> m >> s >> v;

    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b;
        cin >> e[i].r1 >> e[i].c1 >> e[i].r2 >> e[i].c2;
    }

    if (bellman_ford())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

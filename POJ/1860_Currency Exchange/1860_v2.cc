#include <cstdio>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
    double r, c;
    Edge(int _u, int _v, double _r, double _c) : u(_u), v(_v), r(_r), c(_c) {}
};

int n;
double Money[110];
vector<Edge> E;

bool bellman_ford(int x) {
    bool flag = true;
    for (int i = 0; flag and i != n; ++i) {
        flag = false;
        for (int j = 0; j != E.size(); ++j) {
            int &u = E[j].u, &v = E[j].v;
            double &r = E[j].r, &c = E[j].c;
            double tmp = (Money[u] - c) * r;
            if (tmp > Money[v]) {
                flag = true;
                Money[v] = tmp;
            }
        }
    } 
    return flag;
}

int main() {
    int m, x;
    double tmp;
    scanf("%d %d %d %lf", &n, &m, &x, &tmp);
    Money[x] = tmp;
    for (int i = 0; i != m; ++i) {
        int A, B;
        double r1, c1, r2, c2;
        scanf("%d %d %lf %lf %lf %lf", &A, &B, &r1, &c1, &r2, &c2);
        E.push_back(Edge(A, B, r1, c1));
        E.push_back(Edge(B, A, r2, c2));
    }

    if (bellman_ford(x))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}


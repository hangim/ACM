#include <iostream>

using namespace std;

int size;

struct Edge {
    int u, v, c;
} E[4010];

const int INF = 1e9;

int D[1010];

int bellman_ford(int n) {
    for (int i = 1; i <= n; ++i)
        D[i] = INF;
    D[n] = 0;
    for (int i = 1; i != n; ++i) {
        for (int j = 0; j != size; ++j) {
            int &u = E[j].u, &v = E[j].v, &c = E[j].c;
            if (D[v] > D[u] + c)
                D[v] = D[u] + c;
        }
    }
    return D[1];
}

int main() {
    int t, n;
    cin >> t >> n;
    size = 0;
    for (int i = 0; i != t; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        E[size].u = u, E[size].v = v, E[size].c = c;
        ++size;
        E[size].u = v, E[size].v = u, E[size].c = c;
        ++size;
    }

    cout << bellman_ford(n) << endl;

    return 0;
}


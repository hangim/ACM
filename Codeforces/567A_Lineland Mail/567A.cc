#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000;

int minn[maxn + 10], maxx[maxn + 10];

struct Node {
    int x, r;
    bool operator < (const Node &o) const {
        return x < o.x;
    }
} node[maxn + 10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node[i].x;
        node[i].r = i;
    }
    sort(node, node + n);
    minn[node[0].r] = node[1].x - node[0].x;
    minn[node[n-1].r] = node[n-1].x - node[n-2].x;
    maxx[node[0].r] = maxx[node[n-1].r] = node[n-1].x - node[0].x;

    for (int i = 1; i < n - 1; ++i) {
        minn[node[i].r] = min(node[i].x - node[i-1].x, node[i+1].x - node[i].x);
        maxx[node[i].r] = max(node[i].x - node[0].x, node[n-1].x - node[i].x);
    }
    for (int i = 0; i < n; ++i)
        cout << minn[i] << " " << maxx[i] << endl;
    return 0;
}


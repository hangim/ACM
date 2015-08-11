#include <bits/stdc++.h>

using namespace std;

int n, m;

struct Edge {
    int u, v, r;
    Edge() {}
    Edge(int _u, int _v, int _r) : u(_u), v(_v), r(_r) {}
};

vector<Edge> e[10];

int bit_count(int x) {
    int c = 0;
    while (x) {
        ++c;
        x -= x&(-x);
    }
    return c;
}

int f(int r, int sta) {
    // cout << "r = " << r << " sta " << sta << endl;
    if (r > n)
        return 1;

    vector<Edge> tmp;
    int cnt = 0;
    for (int i = 0; i < (int)e[r].size(); ++i) {
        if (sta & (1<<e[r][i].r))
            cnt++;
        else
            tmp.push_back(e[r][i]);
    }
    if (cnt > (int)tmp.size())
        return 0;

    int ans = 0;
    for (int i = 0; i < (1 << tmp.size()); ++i) {
        if ((cnt + bit_count(i)) * 2 != (int)e[r].size())
            continue;
        bool flag = false;
        int new_sta = sta;
        for (int j = 0; j < (int)tmp.size(); ++j) {
            if (i & (1 << j)) {
                new_sta |= (1 << tmp[j].r);
                if (tmp[j].v < r)
                    flag = true;
            }
        }
        if (flag)
            continue;
        ans += f(r + 1, new_sta);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; ++i)
            e[i].clear();

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            e[u].push_back(Edge(u, v, i));
            e[v].push_back(Edge(v, u, i));
        }
        
        printf("%d\n", m % 2 ? 0 : f(0, 0));
    }
    return 0;
}


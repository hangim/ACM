#include <bits/stdc++.h>

using namespace std;

int x[710], y[710];
vector<int> v;

inline int f(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &x[i], &y[i]);
        v.clear();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                v.push_back(f(i, j));
        sort(v.begin(), v.end());

        int ans = unique(v.begin(), v.end()) - v.begin();
        printf("Case %d: %d\n", cs, ans + 1);
    }
    return 0;
}


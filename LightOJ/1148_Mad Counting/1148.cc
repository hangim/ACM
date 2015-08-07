#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            m[x + 1]++;
        }
        int ans = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            ans += it->first * ceil(1.0 * it->second / it->first);
        }
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    return x == 0 ? 0 : x / 5 + f(x / 5);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2;
            if (f(m) >= n)
                r = m;
            else
                l = m + 1; 
        }
        if (f(l) == n)
            printf("Case %d: %d\n", cs, l);
        else
            printf("Case %d: impossible\n", cs);
    }
    return 0;
}


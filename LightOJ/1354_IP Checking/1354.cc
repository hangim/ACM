#include <bits/stdc++.h>

using namespace std;

bool equal(int a, int b) {
    int c = 0;
    for (int i = 0; i < 8; i++){
        if (b & 1)
            c |= (1 << i);
        b /= 10;
    }
    return a == c;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int a1, a2, b1, b2, c1, c2, d1, d2;
        scanf("%d.%d.%d.%d", &a1, &b1, &c1, &d1);
        scanf("%d.%d.%d.%d", &a2, &b2, &c2, &d2);
        printf("Case %d: ", cs);
        if (equal(a1, a2) and equal(b1, b2) and equal(c1, c2) and equal(d1, d2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}


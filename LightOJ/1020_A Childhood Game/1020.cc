#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        char s[10];
        scanf("%d %s", &n, s);
        printf("Case %d: ", cs);
        if (strcmp(s, "Alice") == 0) {
            if ((n - 1) % 3 == 0)
                puts("Bob");
            else
                puts("Alice");
        } else {
            if (n % 3 == 0)
                puts("Alice");
            else
                puts("Bob");
        }
    }
    return 0;
}


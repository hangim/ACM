#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int cnt = 0;
    int x, a;
    int maxx = -1e9 - 10;
    while (N--) {
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d", &a);
            cnt++;
            maxx = max(maxx, a);
        } else if (x == 2) {
            --cnt;
            if (cnt == 0)
                maxx = -1e9 - 10;
            cnt = max(cnt, 0);
        } else {
            if (cnt == 0)
                printf("0\n");
            else
                printf("%d\n", maxx);
        }
    }

    return 0;   
}


#include <bits/stdc++.h>

const int maxn = 16000;
bool vis[maxn + 10];
 
void init_pri() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not vis[i]) {
            for (int j = i * i; j <= maxn; j += i)
                vis[j] = true;
        }
}

int main() {
    init_pri();
    int n, k = 1;
    while (scanf("%d", &n) != EOF) {
        if (n <= 0)
            break;
        vis[1] = vis[2] = 1;
        printf("%d: %s\n", k++, vis[n] ? "no" : "yes");
    }
    return 0;
}


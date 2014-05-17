#include <cstdio>

int main() {

    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        long long maxn;
        long long total;
        maxn = total = 0;

        int var;
        for (int i = 0; i < n; i++) {
            scanf("%d", &var);
            if (var > maxn)
                maxn = var;
            total += var;
        }

        if (maxn > total - maxn + 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    

    return 0;
}

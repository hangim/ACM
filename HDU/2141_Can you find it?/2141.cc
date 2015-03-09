#include <cstdio>
#include <set>

using namespace std;

int main() {
    int A[500], B[500], C[500], X[1000];

    int l, n, m, k;
    int cases = 1;
    while (scanf("%d%d%d", &l, &n, &m) == 3) {
        for (int i = 0; i != l; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i != n; ++i)
            scanf("%d", &B[i]);
        for (int i = 0; i != m; ++i)
            scanf("%d", &C[i]);
        scanf("%d", &k);
        for (int i = 0; i != k; ++i)
            scanf("%d", &X[i]);

        set<int> s;
        for (int i = 0; i != l; ++i)
            for (int j = 0; j != n; ++j)
                    s.insert(A[i] + B[j]);

        printf("Case %d:\n", cases++);

        for (int i = 0; i != k; ++i) {
            bool flag = false;
            for (int j = 0; j != m; ++j) {
                if (s.find(X[i] - C[j]) != s.end()) {
                    flag = true;
                    break;
                }
            }
            printf("%s\n", flag ? "YES" : "NO");
        }
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int A[1000000];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i != n; ++i)
            scanf("%d", &A[i]);
        sort(A, A + n);
        printf("%d\n", A[n/2]);
    }
    return 0;
}


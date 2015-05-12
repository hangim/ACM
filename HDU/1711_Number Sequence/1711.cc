#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[1000010], B[10010], Next[10010];

void get_Next() {
    Next[0] = -1;
    int k = -1, j = 0;
    while (j != m) {
        if (k == -1 or B[j] == B[k]) {
            ++k, ++j;
            if (B[j] == B[k])
                Next[j] = Next[k];
            else
                Next[j] = k;
        } else {
            k = Next[k];
        }
    }
}

int kmp() {
    get_Next();

    int i = 0, j = 0;
    while (i != n and j != m) {
        if (j == -1 or A[i] == B[j])
            ++i, ++j;
        else
            j = Next[j];
    }

    if (j == m)
        return i - j + 1;
    else
        return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i != n; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i != m; ++i)
            scanf("%d", &B[i]);
        printf("%d\n", kmp());
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n, p;
char A[1010], P[1010];
int Next[1010];

void get_next() {
    int k = Next[0] = -1;
    int i = 0;
    while (i != p) {
        if (k == -1 or P[i] == P[k]) {
            ++i, ++k;
            if (P[i] == P[k])
                Next[i] = Next[k];
            else
                Next[i] = k;
        } else {
            k = Next[k];
        }
    }
}

int kmp() {
    int i = 0, j = 0;
    int ans = 0;
    while (i != n) {
        if (j == -1 or A[i] == P[j]) {
            ++i, ++j;
        } else {
            j = Next[j];
        }
        if (j == p) {
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main() {
    while (scanf("%s", A) != EOF and A[0] != '#') {
        scanf("%s", P);
        n = strlen(A);
        p = strlen(P);
        get_next();
        printf("%d\n", kmp());
    }

    return 0;
}


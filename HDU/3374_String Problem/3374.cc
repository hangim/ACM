#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;
char s[MAXN];
int Next[MAXN];
int len;

void get_next() {
    int k = Next[0] = -1, j = 0;
    while (j != len) {
        if (k == -1 or s[k] == s[j])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}

/* 最小表示法 */
int get_min_express() {
    int i = 0, j = 1, k = 0;
    while (i < len and j < len and k < len) {
        int sgn = s[(i+k)%len] - s[(j+k)%len];
        if (sgn == 0) {
            ++k;
        } else if (sgn > 0) {
            i += k + 1;
            k = 0;
        } else if (sgn < 0) {
            j += k + 1;
            k = 0;
        }
        if (i == j)
            ++i;
    }
    return min(i, j);
}

int get_max_express() {
    int i = 0, j = 1, k = 0;
    while (i < len and j < len and k < len) {
        int sgn = s[(i+k)%len] - s[(j+k)%len];
        if (sgn == 0) {
            ++k;
        } else if (sgn > 0) {
            j += k + 1;
            k = 0;
        } else if (sgn < 0) {
            i += k + 1;
            k = 0;
        }
        if (i == j)
            ++i;
    }
    return min(i, j);
}

int main() {
    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        int t = 1, min_express, max_express;
        get_next();
        if (Next[len] and len % (len - Next[len]) == 0)
            t = len / (len - Next[len]);
        min_express = get_min_express();
        max_express = get_max_express();
        printf("%d %d %d %d\n", min_express + 1, t, max_express + 1, t);
    }
    return 0;
}


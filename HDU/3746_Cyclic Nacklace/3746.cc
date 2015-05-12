#include <bits/stdc++.h>

char str[100010];
int Next[100010];
int len;

void get_next() {
    int i = 0;
    int k = Next[0] = -1;
    while (i != len) {
        if (k == -1 or str[i] == str[k])
            Next[++i] = ++k;
        else
            k = Next[k];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        len = strlen(str);
        get_next();

        int cycle_len = len - Next[len];
        if (len % cycle_len == 0 and cycle_len != len)
            printf("0\n");
        else
            printf("%d\n", cycle_len - Next[len] % cycle_len);
    }
    return 0;
}


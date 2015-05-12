#include <cstdio>
#include <cstring>

int len;
char S[1000010];
int nextval[1000010];

void get_nextval() {
    int k = nextval[0] = -1, j = 0;
    while (j != len) {
        if (k == -1 or S[j] == S[k])
            nextval[++j] = ++k;
        else
            k = nextval[k];
    }
}

int main() {
    while (scanf("%s", S) != EOF and S[0] != '.') {
        len = strlen(S);
        get_nextval();
        if (nextval[len] != 0 and len % (len - nextval[len]) == 0)
            printf("%d\n", len / (len - nextval[len]));
        else
            printf("%d\n", 1);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int len;
char S[1000010];
int nextval[1000010];

void get_nextval() {
    int k = nextval[0] = -1;
    int j = 0;
    while (j != len) {
        if (k == -1 or S[j] == S[k])
            nextval[++j] = ++k;
        else
            k = nextval[k];
    }
}

int main() {
    while (scanf("%s", S) != EOF) {
        len = strlen(S);
        get_nextval();
        printf("%d\n", len - nextval[len]);
    }
    return 0;
}


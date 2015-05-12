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
    int cases = 1;
    while (scanf("%d", &len) != EOF and len) {
        scanf("%s", S);
        get_nextval();
        printf("Test case #%d\n", cases++);
        for (int i = 1; i <= len; ++i) {
            if (nextval[i] != 0 and i % (i - nextval[i]) == 0)
                printf("%d %d\n", i, i / (i - nextval[i]));
        }

        printf("\n");
    }

    return 0;
}


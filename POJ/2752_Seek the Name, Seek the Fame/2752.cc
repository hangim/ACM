#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

int len;
char S[400010];
int nextval[400010];

void get_nextval() {
    for (int k = nextval[0] = -1, j = 0; j != len; ) {
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
        stack<int> s;
        for (int k = len; k != 0; k = nextval[k])
            s.push(k);
        while (not s.empty()) {
            printf("%d ", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}

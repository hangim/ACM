#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m;
int len;
char S[10][61];
int nextval[61];

void get_nextval(const char *pat) {
    int k = nextval[0] = -1;
    int j = 0;
    while (j != len) {
        if (k == -1 or pat[j] == pat[k])
            nextval[++j] = ++k;
        else
            k = nextval[k];
    }
}

int kmp(const char *pat) {
    get_nextval(pat);

    int ans = 60;
    for (int i = 1; i != m; ++i) {
        int tmp = 0, k = 0, j = 0;
        while (j != 60 and k != len) {
            if (k == -1 or S[i][j] == pat[k])
                ++j, ++k;
            else
                k = nextval[k];
            tmp = max(tmp, k);
        }
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        for (int i = 0; i != m; ++i)
            scanf("%s", S[i]);

        int ans = 0;
        char ansd[61];
        for (len = 1; len <= 60; ++len) {
            int tmp = kmp(S[0] + 60 - len);
            if (tmp > ans or (tmp == ans and strncmp(ansd, S[0] + 60 - len, tmp) > 0)) {
                ans = tmp;
                strncpy(ansd, S[0] + 60 - len, tmp);
                ansd[tmp] = '\0';
            }
        }
        
        if (ans < 3)
            printf("no significant commonalities\n");
        else
            printf("%s\n", ansd);
    }
    return 0;
}


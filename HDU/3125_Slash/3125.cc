#include <bits/stdc++.h>

using namespace std;

char s[55];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int len = strlen(s);
        if (s[0] == '/' or s[0] == '\\') {
            printf("It's a path in Unix-like systems!\n");
            for (int i = 0; i < len; ++i)
                if (s[i] == '\\')
                    s[i] = '/';
            printf("%s\n", s);
            continue;
        }
        if (s[1] == ':' and (s[3] != '\\' and s[3] != '/')) {
            printf("It's a path in Windows system!\n");
            for (int i = 0; i < len; ++i)
                if (s[i] == '/')
                    s[i] = '\\';
            printf("%s\n", s);
            continue;
        }
        printf("It's a URL!\n");
        for (int i = 0; i < len; ++i)
            if (s[i] == '\\')
                s[i] = '/';
        printf("%s\n", s);
    }
    return 0;
}


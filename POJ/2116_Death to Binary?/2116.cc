#include <cstdio>
#include <cstring>

using namespace std;

char buf[50];
char s1[50], s2[50], s3[50];


bool input(char *s) {
    if (scanf("%s", buf) == EOF)
        return false;
    int len = strlen(buf);
    for (int i = 0; i < len; ++i)
        s[i] = buf[len-1-i] - '0';
    return true;
}

void output(char *s) {
    bool flag = false;
    for (int i = 45; i >= 0; --i) {
        if (s[i])
            flag = true;
        if (flag)
            printf("%c", s[i] + '0');
    }
    printf("%s\n", flag ? "" : "0");
}

int canonical(char *s) {
    bool flag;
    do {
        flag = false;
        for (int i = 0; i <= 45; ++i) {
            if (s[i] >= 1 and s[i+1] >= 1 and s[i+2] == 0)
                --s[i], --s[i+1], ++s[i+2] = 1, flag = true;
            if (i == 0 and s[i] >= 2)
                s[i] -= 2, ++s[i+1], flag = true;
            if (i == 1 and s[i] >= 2)
                s[i] -= 2, ++s[i+1], ++s[i-1], flag = true;
            if (i > 1 and s[i] >= 2)
                s[i] -= 2, ++s[i+1], ++s[i-2], flag = true;
        }
    } while (flag);

    for (int i = 45; i >= 0; --i)
        if (s[i]) return i + 1;
    return 1;
}

void add() {
    for (int i = 0; i <= 45; ++i)
        s3[i] = s1[i] + s2[i];
}

int main() {
    while (true) {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(s3, 0, sizeof(s3));
        memset(buf, 0, sizeof(buf));

        if (input(s1) == false)
            break;
        int len1 = canonical(s1);
        input(s2);
        int len2 = canonical(s2);
        add();
        int len3 = canonical(s3);
    
        while (len1 < len3 + 2) {
            putchar(' ');
            ++len1;
        }
        output(s1);

        putchar('+');
        while (len2 < len3 + 1) {
            putchar(' ');
            ++len2;
        }
        output(s2);

        printf("  ");
        while (len3--)
            putchar('-');
        putchar('\n');
 
        printf("  ");
        output(s3);
        printf("\n");
    }
    return 0;
}


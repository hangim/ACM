#include <cstdio>
#include <cstring>
#include <ciso646>

int w, t;
char word[10010], text[1000010];
int Next[10010];

void get_next() {
    Next[0] = -1;
    int k = -1, i = 0;
    while (i != w) {
        if (k == -1 or word[i] == word[k]) {
            ++i, ++k;
            if (word[i] == word[k])
                Next[i] = Next[k];
            else
                Next[i] = k;
        } else {
            k = Next[k];
        }
    }
}

int kmp() {
    int ans = 0;

    int i = 0, j = 0;
    while (i != t) {
        if (j == -1 or text[i] == word[j])
            ++i, ++j;
        else
            j = Next[j];

        if (j == w) {
            ++ans;
            j = Next[j];
        }
    }
    
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", word);
        scanf("%s", text);

        w = strlen(word);
        t = strlen(text);
        get_next();

        printf("%d\n", kmp());
    }
    return 0;
}


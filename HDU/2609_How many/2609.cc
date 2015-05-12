#include <bits/stdc++.h>

using namespace std;

int len;
char s[210];

int get_min_express() {
    int i = 0, j = 1, k = 0;
    while (i < len and j < len and k < len) {
        if (s[i+k] > s[j+k]) {
            i += k + 1;
            k = 0;
        } else if (s[i+k] < s[j+k]) {
            j += k + 1;
            k = 0;
        } else {
            k++;
        }
        if (i == j)
            ++i;
    }
    return min(i, j);
}

set<string> rsu;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        rsu.clear();
        while (n--) {
            scanf("%s", s);
            len = strlen(s);
            for (int i = 0; i != len; ++i)
                s[i+len] = s[i];
            int min_express = get_min_express();
            s[min_express + len] = '\0';
            rsu.insert(s + min_express);
        }
        printf("%ld\n", rsu.size());
    }
    return 0;
}


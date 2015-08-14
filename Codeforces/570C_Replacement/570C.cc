#include <bits/stdc++.h>

using namespace std;

char s[300010];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (s[i-1] == '.' and s[i] == '.')
            cnt++;
    for (int i = 0; i < m; ++i) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        if (s[x] == c) {
            ;
        } else if (c == '.') {
            if (s[x-1] == '.' and s[x+1] == '.')
                cnt += 2;
            else if (s[x-1] == '.' or s[x+1] == '.')
                cnt++;
        } else {
            if (s[x] != '.')
                ;
            else if (s[x-1] == '.' and s[x+1] == '.')
                cnt -= 2;
            else if (s[x-1] == '.' or s[x+1] == '.')
                cnt--;
        }
        s[x] = c;
        cout << cnt << endl;
    }
    return 0;
}


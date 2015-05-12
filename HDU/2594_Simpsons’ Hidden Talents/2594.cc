#include <bits/stdc++.h>

using namespace std;

int len, len1;
char s[100010];
int nextval[100010];

void get_next() {
    int k = nextval[0] = -1, j = 0;
    while (j != len) {
        if (k == -1 or s[k] == s[j])
            nextval[++j] = ++k;
        else
            k = nextval[k];
    }
}

int main() {
    while (cin >> s) {
        len1 = strlen(s);
        s[len1] = '*';
        cin >> (s + len1 + 1);
        len = strlen(s);

        get_next();

        if (nextval[len])
            cout << s + len - nextval[len] << " ";
        cout << nextval[len] << endl;
    }
    return 0;
}


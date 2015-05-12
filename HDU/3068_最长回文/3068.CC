#include <bits/stdc++.h>

using namespace std;

int len;
char in[110010], s[220010];
int nRad[220010];

int manacher() {
    memset(nRad, 0, sizeof(nRad));
    int maxRad = 0, j = 0, maxx = 0;
    for (int i = 1; i != len; ++i) {
        if (i < maxx)
            nRad[i] = min(nRad[2 * j - i], maxx - i);
        else
            nRad[i] = 1;

        while (s[i - nRad[i]] == s[i + nRad[i]])
            ++nRad[i];

        if (maxRad < nRad[i])
            maxRad = nRad[i];

        if (i + nRad[i] > maxx) {
            j = i;
            maxx = i + nRad[i];
        }
    }
    return maxRad - 1;
}

int main() {
    memset(s, '#', sizeof(s));
    s[0] = '$';
    while (cin >> in) {
        len = strlen(in);
        for (int i = 0; i != len; ++i)
            s[(i + 1) * 2] = in[i];
        len = (len + 1) * 2;
        cout << manacher() << endl;
    }
    return 0;
}


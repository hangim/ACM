#include <iostream>
#include <cstring>

using namespace std;

int len;
char in[1000010], s[2000010];
int nRad[2000010];

int manacher() {
    memset(nRad, 0, sizeof(nRad));
    int maxRad, j, maxx;
    maxRad = j = maxx = 0;

    for (int i = 1; i != len; ++i) {
        if (i < maxx)
            nRad[i] = min(nRad[2*j-i], maxx-i);
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
    int cases = 1;
    while (cin >> in) {
        if (strncmp(in, "END", 3) == 0)
            break;
        len = strlen(in);
        memset(s, '#', sizeof(s));
        s[0] = '$';
        for (int i = 0; i != len; ++i)
            s[(i+1)*2] = in[i];
        len = (len + 1) * 2;

        int ans = manacher();
        cout << "Case " << cases++ << ": " << ans << endl;
    }
    return 0;
}


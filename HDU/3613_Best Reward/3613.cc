#include <bits/stdc++.h>

using namespace std;

int table[128];
char s[500010], t[500010];
int sum[500010];
int extend1[500010], extend2[500010];
int Next[500010];

void EKMP_getNext(char *t, int len) {
    Next[0] = len;
    for (int i = 0; i != len and t[0] == t[i]; ++i)
        Next[1] = i;
    int k = 1;
    for (int i = 2; i < len; i++) {
        int p = k + Next[k];
        int L = Next[i-k];
        if (i + L < p) {
            Next[i] = L;
        } else {
            int j = max(0, p - i);
            while (i + j < len and t[i+j] == t[j])
                j++;
            Next[i] = j;
            k = i;
        }
    }
}

void EKMP(char *s, char *t, int len, int *extend) {
    EKMP_getNext(t, len);
    extend[0] = 0;
    for (int i = 0; i != len and s[i] == t[i]; ++i)
        extend[0] = i;
    int k = 0;
    for (int i = 1; i != len; ++i) {
        int p = k + extend[k];
        int L = Next[i-k];
        if (i + L < p) {
            extend[i] = L;
        } else {
            int j = max(0, p - i);
            while (i + j != len and s[i+j] == t[j])
                ++j;
            extend[i] = j;
            k = i;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 'a'; i <= 'z'; ++i)
            cin >> table[i];
        cin >> s;
        int len = strlen(s);
        for (int i = 0; i != len; ++i)
            t[i] = s[len-i-1];
        t[len] = '\0';

        sum[0] = table[s[0]];
        for (int i = 1; i != len; ++i)
            sum[i] = sum[i-1] + table[s[i]];

        EKMP(t, s, len, extend1);
        EKMP(s, t, len, extend2);

        int ans = INT_MIN;
        for (int i = 1; i != len; ++i) {
            int tmp = 0;
            if (extend1[len-i] + len-i == len)
                tmp += sum[i-1];
            if (extend2[i] + i == len)
                tmp += sum[len-1] - sum[i-1];
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}

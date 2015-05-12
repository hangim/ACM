#include <bits/stdc++.h>

using namespace std;

/*
 * 扩展KMP算法
 * s1[]: 主串
 * s2[]: 子串
 * next[i]: s2[i:] 与 s2[0:] 的最长公共前缀
 * extend[i]: s1[i:] 与 s2[:] 的最长公共前缀
 */
void EKMP_getNext(char s2[], int len, int next[]) {
    next[0] = len;
    for (int i = 0; i != len and s2[0] == s2[i]; ++i)
        next[1] = i;
    int k = 1;
    for (int i = 2; i < len; i++) {
        int p = k + next[k]; // 最远到达距离
        int L = next[i-k];
        if (i + L < p) {
            next[i] = L;
        } else {
            int j = max(0, p - i);
            while (i + j < len and s2[i+j] == s2[j])
                j++;
            next[i] = j;
            k = i;
        }
    }
}

void EKMP(char *s1, int n, char *s2, int m, int next[], int extend[]) {
    EKMP_getNext(s2, m, next);
    next[0] = 0;
    for (int i = 0; i != n and i != m and s1[i] == s2[i]; ++i)
        next[0] = i;
    int k = 0;
    for (int i = 1; i != n; ++i) {
        int p = k + extend[k];
        int L = next[i-k];
        if (i + L < p) {
            extend[i] = L;
        } else {
            int j = max(0, p - i);
            while (i + j != n and j != m and s1[i+j] == s2[j])
                ++j;
            extend[i] = j;
            k = i;
        }
    }
}

char table1[27], table2[27], s1[100010], s2[100010];
int next_val[100010], extend[100010];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> table1 >> s1;
        for (int i = 0; i != 26; ++i)
            table2[table1[i]-'a'] = i + 'a';

        int len = strlen(s1);
        for (int i = 0; i != len; ++i)
            s2[i] = table2[s1[i]-'a'];
        s2[len] = '\0';

        EKMP(s1, len, s2, len, next_val, extend);

        for (int i = 0; i != len; ++i) {
            if (i + extend[i] == len and i >= extend[i]) {
                s1[i] = s2[i] = '\0';
                break;
            }
        }
        cout << s1 << s2 << endl;
    }
    return 0;
}


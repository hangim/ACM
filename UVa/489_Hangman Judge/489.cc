#include <bits/stdc++.h>

using namespace std;

int cnt[128];

int main() {
    int k;
    while (cin >> k and k != -1) {
        memset(cnt, 0, sizeof(cnt));
        string str1, str2;
        cin >> str1 >> str2;
        int win = 0, lose = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (cnt[str1[i]] == 0)
                win++;
            ++cnt[str1[i]];
        }
        for (int i = 0; i < str2.length(); ++i) {
            if (cnt[str2[i]] == 0)
                ++lose;
            if (cnt[str2[i]] > 0) {
                cnt[str2[i]] = -1;
                --win;
            }
            if (lose == 7 or win == 0)
                break;
        }
        cout << "Round " << k << endl;
        if (lose == 7)
            cout << "You lose." << endl;
        else if (win == 0)
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}


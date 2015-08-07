#include <bits/stdc++.h>

using namespace std;

int getMonth (string str) {
    string Months[13] = {"",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    for (int i = 1; i <= 12; ++i)
        if (Months[i] == str)
            return i;
    return -1;
}

bool isLeap(int y) {
    return y % 400 == 0 or (y % 4 == 0 and y % 100);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int ans = 0;

        string s1, s2, s;
        int m1, m2, d1, d2, y1, y2;
        cin >> s1 >> d1 >> s >> y1
            >> s2 >> d2 >> s >> y2;
        
        m1 = getMonth(s1);
        m2 = getMonth(s2);

        if (isLeap(y1) and m1 >= 3)
            ans--;
        if (isLeap(y2) and (m2 == 1 or (m2 == 2 and d2 < 29)))
            ans--;

        if (y1 % 4)
            y1 += 4 - y1 % 4;
        if (y2 % 4)
            y2 -= y2 % 4;
        while (y1 <= y2) {
            if (y1 % 400 == 0) {
                ans++;
                break;
            } else if (y1 % 100)
                ans++;
            y1 += 4;
        }
        while (y2 > y1) {
            if (y2 % 400 == 0) {
                ans++;
                break;
            } else if (y2 % 100)
                ans++;
            y2 -= 4;
        }
        if (y2 > y1)
            ans += (y2 - y1) / 400 * 97 - 1;

        printf("Case %d: %d\n", cs, ans);

    }
    return 0;
}


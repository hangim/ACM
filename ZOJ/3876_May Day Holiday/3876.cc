#include <bits/stdc++.h>

using namespace std;

int zeler(int year) {
   int c = year / 100, m = 5, d = 1, y = year % 100;
   int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
   w = (w + 7) % 7;
   return w;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int year;
        cin >> year;
        int ans = 0;
        int w = zeler(year);
        switch (w) {
            case 0: ans = 6; break; // sunday
            case 1: ans = 9; break;
            case 2: ans = 6; break;
            case 3: ans = 5; break;
            case 4: ans = 5; break;
            case 5: ans = 5; break;
            case 6: ans = 5; break;
        }
        cout << ans << endl;
    }
    return 0;
}


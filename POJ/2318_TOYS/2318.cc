#include <iostream>
#include <cstring>

using namespace std;

int cnt[5010], paritions[5010][2], toys[5010][2];

int main() {
    int n, m, x1, y1, x2, y2;
    while (cin >> n and n) {
        memset(cnt, 0, sizeof(cnt));
        cin >> m >> x1 >> y1 >> x2 >> y2;
        
        for (int i = 0; i != n; ++i)
            cin >> paritions[i][0] >> paritions[i][1];
        paritions[n][0] = paritions[n][1] = x2;

        for (int i = 0; i != m; ++i)
            cin >> toys[i][0] >> toys[i][1];

        for (int i = 0; i != m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int &x = toys[i][0], &y = toys[i][1], &u = paritions[j][0], &l = paritions[j][1];
                if ((x < u and x < l) or (x < u + 1.0*(l-u)*(y-y1)/(y2-y1))) {
                    ++cnt[j];
                    break;
                }
            }
        }

        for (int i = 0; i <= n; ++i)
            cout << i << ": " << cnt[i] << endl;
        cout << endl;
    }
    return 0;
}

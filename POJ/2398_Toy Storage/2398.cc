#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int cnt[1010], paritions[1010][2], toys[1010][2], ansd[1010];

int cmp(const void * _a, const void * _b) {
    const int (*a)[2] = (const int (*)[2]) _a;
    const int (*b)[2] = (const int (*)[2]) _b;
    return (*a)[0] - (*b)[0];
}

int main() {
    int n, m, x1, y1, x2, y2;
    while (cin >> n and n) {
        memset(cnt, 0, sizeof(cnt));
        cin >> m >> x1 >> y1 >> x2 >> y2;
        
        for (int i = 0; i != n; ++i)
            cin >> paritions[i][0] >> paritions[i][1];
        paritions[n][0] = paritions[n][1] = x2;
        qsort(paritions, n, sizeof(int[2]), cmp);

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

        memset(ansd, 0, sizeof(ansd));
        for (int i = 0; i <= n; ++i)
            ansd[cnt[i]]++;
        
        cout << "Box" << endl;
        for (int i = 1; i <= m; ++i)
            if (ansd[i])
                cout << i << ": " << ansd[i] << endl;
    }
    return 0;
}

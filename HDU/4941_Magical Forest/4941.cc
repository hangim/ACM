#include <iostream>
#include <map>

using namespace std;

const long long MAXN = 2000000000LL;

long long hash(long long x, long long y) {
    return (x - 1) * MAXN + y - 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w;
    cin >> w;
    int index = 1;
    while (w--) {
        cout << "Case #" << index++ << ":" << endl;

        int n1, m1, k;
        cin >> n1 >> m1 >> k;

        map<long long, int> m;
        for (int i = 0; i < k; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            m[hash(x, y)] = c;
        }
        
        map<int, int> row;
        map<int, int> col;
        int t;
        cin >> t;
        while (t--) {
            int q, a, b;
            cin >> q >> a >> b;
            int x, y;
            if (q == 1) {
                if (row.find(a) != row.end())
                    x = row[a];
                else
                    x = a;
                if (row.find(b) != row.end())
                    y = row[b];
                else
                    y = b;
                row[a] = y;
                row[b] = x;

            } else if (q == 2) {
                if (col.find(a) != col.end())
                    x = col[a];
                else
                    x = a;
                if (col.find(b) != col.end())
                    y = col[b];
                else
                    y = b;
                col[a] = y;
                col[b] = x;
            
            } else {
                if (row.find(a) != row.end())
                    x = row[a];
                else
                    x = a;
                if (col.find(b) != col.end())
                    y = col[b];
                else
                    y = b;
                cout << m[hash(x, y)] << endl;
            }
        }
    }

    return 0;
}


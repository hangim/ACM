#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int m, n;
string *w;
string str;
int len;

bool search(int i, int j);
bool isIn(int i, int j);

int main() {

    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        w = new string[m];
        for (int i = 0; i < m; i++) {
            cin >> w[i];
            transform(w[i].begin(), w[i].end(), w[i].begin(), ::tolower);
        }

        int k;
        cin >> k;
        while (k--) {
            cin >> str;
            transform(str.begin(), str.end(), str.begin(), ::tolower);

            len = str.length();
            
            bool found = false;
            for (int i = 0; not found and i < m; i++) {
                for (int j = 0; not found and j < n; j++) {
                    if (str[0] == w[i][j] and (found = search(i, j)))
                        cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }

        if (t)
            cout << endl;

        delete [] w;
    }

    return 0;
}

bool isIn(int i, int j) {
    return i >= 0 and i < m and j >= 0 and j < n;
}

bool search(int i, int j) {

    static int x[8] = {1,  1,  0, -1, -1, -1, 0, 1};
    static int y[8] = {0, -1, -1, -1,  0,  1, 1, 1};

    int xx, yy;

    for (int q = 0; q < 8; q++) {
        if (not isIn(i + (len - 1) * y[q], j + (len - 1) * x[q]))
            continue;
        
        for (int k = 0; k < len; k++) {
            xx = j + k * x[q];
            yy = i + k * y[q];
            if (not isIn(yy, xx) or str[k] != w[yy][xx])
                break;
            if (k == len - 1)
                return true;
        }
    }

    return false;
}

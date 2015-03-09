#include <iostream>
#include <cstring>

using namespace std;

char M[22][22];

int dfs(int x, int y) {
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    int ret = 1;
    M[y][x] = '#';
    for (int i = 0; i != 4; ++i) {
        int _x = x + dir[i][0];
        int _y = y + dir[i][1];
        if (M[_y][_x] == '.')
            ret += dfs(_x, _y);
    }
    return ret;

}

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        memset(M, '#', sizeof(M));
        int w, h;
        cin >> w >> h;
        int x, y;
        for (int i = 1; i <= h; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j != str.length(); ++j) {
                M[i][j + 1] = str[j];
                if (str[j] == '@') {
                    y = i;
                    x = j + 1;
                }
            }
        }
        cout << "Case " << k << ": " << dfs(x, y) << endl;
    }

    return 0;
}


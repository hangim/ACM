#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    char str[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> str[i][j];

    int x1, x2, y1, y2;
    bool flag = true;
    for (x1 = 0; flag and x1 < m; x1++)
        for (int i = 0; i < n; i++)
            if (str[i][x1] == '*') {
                x1--;
                flag = false;
                break;
            }

    flag = true;
    for (x2 = m - 1; flag and x2 >= 0; x2--)
        for (int i = 0; i < n; i++)
            if (str[i][x2] == '*') {
                x2++;
                flag = false;
                break;
            }

    flag = true;
    for (y1 = 0; flag and y1 < n; y1++)
        for (int i = 0; i < m; i++)
            if (str[y1][i] == '*') {
                y1--;
                flag = false;
                break;
            }

    flag = true;
    for (y2 = n-1; flag and y2 >= 0; y2--)
        for (int i = 0; i < m; i++)
            if (str[y2][i] == '*') {
                y2++;
                flag = false;
                break;
            }

    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            cout << str[i][j];
        }
        cout << endl;
    }

    return 0;
}

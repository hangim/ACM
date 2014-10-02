#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int m[102][102];

int main() {
    memset(m, 0, sizeof(m));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'o')
                m[i][j+1] = 1;
        }
    }

    bool flag = true;
    for (int i = 1; flag and i <= n; i++) {
        for (int j = 1; flag and j <= n; j++) {
            if ((m[i-1][j] + m[i+1][j] + m[i][j-1] + m[i][j+1]) % 2)
                flag = false;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int len[1001];
int rsu[1001][51];
int mod = 1000 * 10000;

void init() {
    memset(rsu, 0, sizeof(rsu));
    rsu[1][0] = 1;
    rsu[2][0] = 2;
    rsu[3][0] = 4;
    rsu[4][0] = 7;

    for (int i = 5; i < 1001; i++) {
        int var = 0;
        for (int j = 0; j < 51; j++) {
            rsu[i][j] = var + rsu[i-1][j] + rsu[i-2][j] + rsu[i-4][j];
            var = rsu[i][j] / mod;
            rsu[i][j] %= mod;
        }
    }
}

void output(int n) {
    int i;
    for (i = 50; rsu[n][i] == 0; i--)
        ;
    cout << rsu[n][i];

    for (--i ; i >= 0; i--)
        cout << setw(7) << setfill('0') << rsu[n][i];
    cout << endl;
}

int main() {

    init();

    int n;
    while (cin >> n) {
        output(n);
    }

    return 0;
}

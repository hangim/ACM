#include <iostream>

using namespace std;

long long fMemo[1001]; // 平面分空间
long long gMemo[1001]; // 直线分平面

void init() {
    gMemo[1] = 2;
    for (int i = 2; i < 1001; i++)
        gMemo[i] = gMemo[i - 1] + i;

    fMemo[1] = 2;
    for (int i = 2; i < 1001; i++)
        fMemo[i] = fMemo[i-1] + gMemo[i-1];
}

int main() {

    init();

    int n;
    while (cin >> n) {
        cout << fMemo[n] << endl;
    }

    return 0;
}

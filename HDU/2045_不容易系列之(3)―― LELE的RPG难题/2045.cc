#include <iostream>

using namespace std;

long long fMemo[51];
long long gMemo[51];

long long f(int n) {
    // 链着色
    if (fMemo[n] != -1)
        return fMemo[n];

    long long sum = 3;
    for (int i = 2; i <= n; i++)
        sum *= 2;

    return fMemo[n] = sum;
}

long long g(int n) {
    // 环着色
    if (gMemo[n] != -1)
        return gMemo[n];

    return gMemo[n] = f(n) - g(n-1);
 }

 int main() {
 
    for (int i = 0; i < 51; i++)
        fMemo[i] = gMemo[i] = -1;
    gMemo[1] = 3;
    gMemo[2] = 6;

    int n;
    while (cin >> n) {
        cout << g(n) << endl;
    }

    return 0;
 }

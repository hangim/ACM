#include <iostream>

using namespace std;

int main() {

    long long *memo = new long long[10001];
    memo[1] = 2;
    for (int i = 2; i < 10001; i++)
        memo[i] = memo[i-1] + 4 * (i - 1) + 1;

    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        cout << memo[n] << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int memo[10001];

int fun(int a, int b) {
    if (memo[b] != -1)
        return memo[b];

    if (b == 1)
        return a;

    if (memo[b / 2] == -1)
        memo[b / 2] = fun(a, b / 2);
        
    if (b % 2 == 0)
        memo[b] = memo[b / 2] * memo[b / 2] % 1000;
    else
        memo[b] = memo[b / 2] * memo[b / 2] * a % 1000;

    return memo[b];
}

int main() {
    
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 and b == 0)
            break;
        for (int i = 0; i < 10001; i++)
            memo[i] = -1;
        a = a % 1000;
        cout << fun(a, b) << endl;
    }

    return 0;
}

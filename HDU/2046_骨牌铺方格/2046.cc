#include <iostream>

using namespace std;

int main() {

    long long memo[51];
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i < 51; i++)
        memo[i] = memo[i-1] + memo[i-2];

    int n;
    while (cin >> n)
        cout << memo[n] << endl;

    return 0;
}

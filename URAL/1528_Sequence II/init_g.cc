#include <iostream>

// g(n) = n

using namespace std;

int n = 20;
int g[10001];
void initG() {
    g[1] = 1;
    g[2] = 2;
    for (int i = 3; i < n; i++)
        g[i] = g[i-2] * g[i-2] + (3 - g[i-1]) * g[i-1];
}

int main() {

    initG();
    for (int i = 1; i < n; i++)
        cout << g[i] << endl;

    return 0;
}


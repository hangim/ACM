#include <iostream>

// g(n) = n;
// see init_g.cc

// f(1) = 1
// f(n) = f(n-1) * (1 + g(n-1))
//      = f(n-1) * n

long long f(int n, int p) {
    long long r = 1;
    for (int i = 2; i <= n; i++)
        r = r * i % p;
    return r;
}

using namespace std;

int main() {

    int n, p;
    while (cin >> n >> p and n and p)
        cout << f(n, p) << endl;

    return 0;
}


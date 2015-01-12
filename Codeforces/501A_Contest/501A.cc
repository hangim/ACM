#include <bits/stdc++.h>

using namespace std;

int f(int p, int t) {
    return max(3 * p / 10, p - p * t / 250);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = f(a, c);
    int v = f(b, d);
    
    if (m > v)
        cout << "Misha" << endl;
    else if (m < v)
        cout << "Vasya" << endl;
    else
        cout << "Tie" << endl;
    
    return 0;
}


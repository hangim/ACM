#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    
    int y, w;
    cin >> y >> w;
    int var = y > w ? y : w;
    --var;
    
    cout << (6 - var) / gcd(var, 6) << "/" << 6 / gcd(var, 6) << endl;
    
    return 0;
}

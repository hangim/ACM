#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = n / 2;
    if (n % 2)
        ans -= n;
    
    cout << ans << endl;

    return 0;
}


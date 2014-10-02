#include <iostream>

using namespace std;

bool func(long long n, long long k, long long d1, long long d2) {
    if (n % 3)
        return false;

    long long rem = n - k;
    long long t;
    // "\/"
    t = rem - 2 * max(d1, d2) + min(d1, d2);
    if (d1 + d2 <= k and t >= 0 and t % 3 == 0)
        return true;

    // "/\"
    t = rem - d1 - d2;
    if (2 * max(d1, d2) - min(d1, d2) <= k and t >= 0 and t % 3 == 0)
        return true;

    // "\\"
    t = rem - 2 * d1 - d2;
    if (d1 + 2 * d2 <= k and t >= 0 and t % 3 == 0)
        return true;

    // "//"
    t = rem - d1 - 2 * d2;
    if (2 * d1 + d2 <= k and t >= 0 and t % 3 == 0)
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) {
        long long n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;

        if (func(n, k, d1, d2))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}


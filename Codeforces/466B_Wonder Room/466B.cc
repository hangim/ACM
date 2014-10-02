#include <iostream>

using namespace std;

int main() {
    long long n, a, b;
    long long s = 1e18, a1, b1;
    cin >> n >> a >> b;

    if (a * b >= 6 * n) {
        s = a * b;
        a1 = a;
        b1 = b;
    } else {
        bool flag = false;
        if (a > b) {
            swap(a, b);
            flag = true;
        }

        for (long long i = a; i * i <= 6 * n; i++) {
            long long j = 6 * n / i;
            if (i * j < 6 * n)
                j++;
            if (j < b)
                continue;
            if (i * j < s) {
                s = i * j;
                a1 = i;
                b1 = j;
            }
        }

        if (flag)
            swap(a1, b1);
    }
    
    cout << s << endl << a1 << " " << b1 << endl;

    return 0;
}


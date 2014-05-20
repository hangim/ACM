#include <iostream>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        long long s2, s3, s4;
        s2 = s3 = s4 = 0;

        for (int i = 1; i <= n; i++) {
            s2 += i * i;
            s3 += i * i * i;
            s4 += i * i * i * i;
        }

        long long temp = n * (n + 1) / 2;
        long long r2 = temp * temp - s2;
        long long r3 = temp * temp * temp - s3;
        long long r4 = temp * temp * temp * temp - s4;

        cout << s2 << " " << r2 << " "
             << s3 << " " << r3 << " "
             << s4 << " " << r4 << endl;
    }

    return 0;
}

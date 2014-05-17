#include <iostream>

using namespace std;

int main() {

    long long n;
    while (cin >> n) {
        if (n < 0)
            break;
        if (n == 1)
            cout << "0%" << endl;
        else
            cout << 25 * n << "%" << endl;
    }

    return 0;
}

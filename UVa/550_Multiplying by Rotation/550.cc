#include <iostream>

using namespace std;

int main() {

    int base, last, k;
    while (cin >> base >> last >> k) {
        int len = 1;
        int a = last * k;

        while (a != last) {
            a = a % base * k + a / base;
            len++;
        }

        cout << len << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int fun(int a, int b) {
    if (b == 1)
        return a;

    int var = fun(a, b / 2);

    if (b % 2 == 0)
        return var * var % 10;
    else
        return var * var * a % 10;
}

int main() {

    int k;
    cin >> k;

    while (k--) {
        int a;
        cin >> a;
        cout << fun(a % 10, a) << endl;
    }

    return 0;
}

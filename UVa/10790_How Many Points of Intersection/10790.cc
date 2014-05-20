#include <iostream>

using namespace std;

int main() {

    int index = 0;
    int a, b;
    while (cin >> a >> b) {
        if (a == 0)
            break;

        long long sum = (a - 1) * a / 2;
        long long var = (b - 1) * b / 2;
        sum *= var;

        cout << "Case " << ++index << ": ";
        cout << sum << endl;
    }

    return 0;
}

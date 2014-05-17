#include <iostream>

using namespace std;

bool isRightTriangle(int a, int b, int c) {
    a = a * a;
    b = b * b;
    c = c * c;
    return a + b == c or a + c == b or b + c == a;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (isRightTriangle(a, b, c))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

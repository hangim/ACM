#include <iostream>

using namespace std;

int getNumLen(int a) {
    int i = 0;
    while (a) {
        ++i;
        a /= 10;
    }
    return i;
}

int main() {

    int a, b;
    while (cin >> a >> b) {
        cout << getNumLen(a + b) << endl;
    }

    return 0;
}

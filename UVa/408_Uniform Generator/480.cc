#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int m, int n) {

    while (n) {
        int t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int main() {

    int seed, step;

    while (cin >> seed >> step) {
        cout << setiosflags(ios::right) << setw(10) << seed
             << setiosflags(ios::right) << setw(10) << step
             << "    ";

        if (gcd(seed, step) == 1)
            cout << "Good Choice" << endl << endl;
        else
            cout << "Bad Choice" << endl << endl;
    }

    return 0;
}

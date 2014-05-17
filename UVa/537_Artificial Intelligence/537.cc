#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

bool isContinue();
double getPrefix();

int main() {
    int t;
    cin >> t;
    cin.get();
    for (int index = 1; index <= t; index++) {
        double u = -1, p = -1, i = -1;
        char var;
        while (true) {
            var = getchar();
            if (var == '\n')
                break;

            if (var == 'U') {
                if (isContinue()) {
                    cin >> u;
                    u *= getPrefix();
                }
            } else if (var == 'P') {
                if (isContinue()) {
                    cin >> p;
                    p *= getPrefix();
                }
            } else if (var == 'I') {
                if (isContinue()) {
                    cin >> i;
                    i *= getPrefix();
                }
            }
        }

        cout << "Problem #" << index << endl;
        cout << setprecision(2) << fixed;
        if (p == -1)
            cout << "P=" << u * i << "W" << endl;
        else if (i == -1)
            cout << "I=" << p / u << "A" << endl;
        else
            cout << "U=" << p / i << "V" << endl;

        cout << endl;
    }

    return 0;
}

bool isContinue() {
    char var = getchar();
    if (var == '=')
        return true;
    else
        return false;
}

double getPrefix() {
    char var;
    cin >> var;
    if (var == 'm')
        return 1e-3;
    if (var == 'k')
        return 1e3;
    if (var == 'M')
        return 1e6;
    return 1.0;
}

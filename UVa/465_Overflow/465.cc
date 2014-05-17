#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    int maxn = 0x7FFFFFFF;
    double num1, num2;
    string var1, var2, op;
    while (cin >> var1 >> op >> var2) {
        cout << var1 << " " << op << " " << var2 << endl;
        num1 = atof(var1.c_str());
        num2 = atof(var2.c_str());

        if (num1 > maxn)
            cout << "first number too big" << endl;
        if (num2 > maxn)
            cout << "second number too big" << endl;
        if (op == "+" and num1 + num2 > maxn or
            op == "*" and num1 * num2 > maxn)
            cout << "result too big" << endl;
    }

    return 0;
}

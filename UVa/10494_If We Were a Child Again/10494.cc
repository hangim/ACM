#include <iostream>
#include <string>

using namespace std;

int main() {

    string num1, op;
    long long num2, rem, tmp;
    while (cin >> num1 >> op >> num2) {
        int len = num1.length();
        rem = tmp = 0;

        if (op == "/") {
            bool flag = false;
            for (int i = 0; i < len; i++) {
                rem = rem * 10 + num1[i] - '0';
                tmp = rem / num2;
                rem = rem % num2;
                if (tmp) {
                    cout << tmp;
                    flag = true;
                } else if (flag) {
                    cout << 0;
                }
            }
            if (not flag)
                cout << 0;
            cout << endl;
        } else {
            for (int i = 0; i < len; i++) {
                rem = rem * 10 + num1[i] - '0';
                rem = rem % num2;
            }
            cout << rem << endl;
        }
    }

    return 0;
}

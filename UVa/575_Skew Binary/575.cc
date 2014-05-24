#include <iostream>

using namespace std;

int main() {

    string str;
    while (cin >> str) {
        if (str == "0")
            break;

        int len = str.length();
        int base = 2;
        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            ans += (str[i] - '0' ) * (base - 1);
            base *= 2;
        }

        cout << ans << endl;
    }

    return 0;
}

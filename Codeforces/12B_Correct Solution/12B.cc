#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string num;
    string ans;

    cin >> num >> ans;

    sort(num.begin(), num.end());

    int len = num.length();
    for (int i = 0; i < len; i++) {
        if (num[i] != '0') {
            char t = num[0];
            num[0] = num[i];
            num[i] = t;
            break;
        }
    }

    if (num == ans)
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;

    return 0;
}

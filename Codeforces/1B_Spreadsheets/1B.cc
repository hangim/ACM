#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {

        string str;
        cin >> str;

        int pos = str.find('C');
        if (str[0] == 'R' and str[1] >= '0' and str[1] <= '9' and pos != str.npos) {
            stack<char> s;

            for (int i = pos - 1; i > 0; i--)
                s.push(str[i]);

            int x = 0;
            for (int i = pos + 1; i < str.length(); i++)
                x = x * 10 + str[i] - '0';
            while (x) {
                if (x % 26 == 0) {
                    s.push('Z');
                    x = x / 26 - 1;
                } else {
                    s.push(x % 26 + 'A' - 1);
                    x = x / 26;
                }
            }

            while (not s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << endl;
        } else {
            int x = 0, y = 0;
            int i;
            for (i = 0; i < str.length(); i++) {
                if (str[i] >= 'A' and str[i] <= 'Z')
                    y = y * 26 + str[i] - 'A' + 1;
                else
                    x = x * 10 + str[i] - '0';
            }
            cout << "R" << x << "C" << y << endl;
        }
    }

    return 0;
}

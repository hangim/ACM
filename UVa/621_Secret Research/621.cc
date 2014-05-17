#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int len = str.length();
        if (str == "1" or str == "4" or str == "78")
            cout << "+" << endl;
        else if (len >= 2 and str[len - 2] == '3' and str[len - 1] == '5')
            cout << "-" << endl;
        else if (str[0] == '9' and str[len-1] == '4')
            cout << "*" << endl;
        else if (len >= 3 and str.substr(0, 3) == "190")
            cout << "?" << endl;
    }

    return 0;
}

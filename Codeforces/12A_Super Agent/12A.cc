#include <iostream>
#include <string>

using namespace std;

int main() {

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    string str4(str3.rbegin(), str3.rend());

    if (str1 == str4 and str2[0] == str2[2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case 'a':
            case 'o':
            case 'y':
            case 'e':
            case 'u':
            case 'i': break;
            default:
                cout << "." << str[i];
        }
    }
    cout << endl;

    return 0;
}


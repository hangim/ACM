#include <iostream>
#include <string>

using namespace std;

int main() {

    string dict = "AAE3HHIIJLLJMM00S2TTUUVVWWXXYYZ5112S3E5Z88";
    int lenDict = dict.length();

    string str;
    while (cin >> str) {
        cout << str;

        int len = str.length();
        for (int i = 0; i < len; i++)
            if (str[i] == 'O')
                str[i] = '0';

        bool isPalindrome = false;
        bool isMirrored = false;

        string var(str.rbegin(), str.rend()); 
        if (var == str)
            isPalindrome = true;

        bool isValid = true;
        for (int i = 0; i < len; i++) {
            bool flag = false;
            for (int j = 0; j < lenDict; j += 2)
                if (var[i] == dict[j]) {
                    var[i] = dict[j + 1];
                    flag = true;
                    break;
                }
            if (flag == false) {
                isValid = false;
                break;
            }
        }

        if (isValid and var == str) {
            isMirrored = true;
        }

        if (isPalindrome and isMirrored)
            cout << " -- is a mirrored palindrome." << endl << endl;
        else if (isPalindrome)
            cout << " -- is a regular palindrome." << endl << endl;
        else if (isMirrored)
            cout << " -- is a mirrored string." << endl << endl;
        else
            cout << " -- is not a palindrome." << endl << endl;
    }

    return 0;
}

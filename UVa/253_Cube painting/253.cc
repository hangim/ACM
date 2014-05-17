#include <iostream>
#include <string>

using namespace std;

int dir[6][6] = {0, 1, 2, 4, 3, 5,
                 1, 3, 5, 2, 0, 4,
                 2, 1, 5, 4, 0, 3,
                 3, 4, 5, 1, 0, 2,
                 4, 0, 2, 5, 3, 1,
                 5, 1, 3, 4, 2, 0};

bool func(string str) {
    string str1, str2;
    str1 = str2 = str.substr(0, 6);

    for (int i = 0; i < 6; i++)
        str1[i] = str[dir[0][i]];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            str2[j] = str[dir[i][j] + 6];
        
        if (str1 == str2)
            return true;
        for (int q = 0; q < 3; q++) {
            char var = str2[1];
            str2[1] = str2[2];
            str2[2] = str2[3];
            str2[3] = str2[4];
            str2[4] = var;
            if (str1 == str2)
                return true;
        }
    }
    return false;
}

int main() {

    string str;
    while (cin >> str) {
        if (func(str))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

    return 0;
}

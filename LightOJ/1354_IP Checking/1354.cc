#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;

bool check(string str1, string str2);

int main() {

    int t;
    cin >> t;
    int index = 1;
    while (t--) {
        string str1;
        string str2;

        cin >> str1 >> str2;

        cout << "Case " << index++ << ": ";
        if (check(str1, str2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

bool check(string str1, string str2){
    int a[4];
    sscanf(str1.c_str(), "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
    for (int i = 0; i < 4; i++){
        int tmp = 0;
        for (int j = 0; j < 8; j++){
            tmp += (str2[i*9 +j] - '0') * pow(2, 7-j);
        }
        if (tmp != a[i])
            return false;
    }
    return true;
}

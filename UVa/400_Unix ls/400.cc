#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    while (cin >> n) {
        vector<string> v;
        int len = 0;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            len = len > str.length() ? len : str.length();
            v.push_back(str);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < 60; i++)
            cout << "-";
        cout << endl;

        int col = (60 + 2) / (len + 2);
        int row = n / col;
        if (row * col < n)
            row++;

        cout << setiosflags(ios::left);
        for (int i = 0; i < row; i++ ) {
            for (int j = 0; j < col and i + j * row < n; j++) {
                if (j == col - 1)
                    cout << setw(len);
                else
                    cout << setw(len + 2);
                
                cout << v[i + j * row];
            }
            cout << endl;
        }
    }

    return 0;
}

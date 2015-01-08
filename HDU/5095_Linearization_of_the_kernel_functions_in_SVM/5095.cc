#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "pqruvwxyz";

    int t;
    cin >> t;
    while (t--) {
        int num[10];
        for (int i = 0; i < 10; ++i)
            cin >> num[i];

        bool flag = false;
        for (int i = 0; i < 9; ++i) {
            if (num[i] == 0)
                continue;

            if (flag) {
                if (num[i] == 1)
                    cout << "+";
                else if (num[i] == -1)
                    cout << "-";
                else if (num[i] > 0)
                    cout << "+" << num[i];
                else
                    cout << num[i];
            } else {
                if (num[i] == 1)
                    ;
                else if (num[i] == -1)
                    cout << "-";
                else
                    cout << num[i];
            }
            cout << str[i];
            flag = true;
        }

        if (flag) {
            if (num[9] > 0)
                cout << "+" << num[9];
            else if (num[9] < 0)
                cout << num[9];
        } else {
            cout << num[9];
        }

        cout << endl;
    }

    return 0;
}


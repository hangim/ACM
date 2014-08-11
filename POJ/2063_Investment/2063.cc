#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Bond {
    int value;
    int interest;
} bonds[11];

int m[46000];

int func(int money, int d) {
    memset(m, 0, sizeof(m));
    money /= 1000;

    for (int i = 0; i <= money; i++) {
        for (int j = 0; j < d; j++) {
            int &value = bonds[j].value;
            int &interest = bonds[j].interest;
            if (i + value <= money)
                m[i+value] = max(m[i+value], m[i] + interest);
        }
    }
    return m[money];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int money, year;
        cin >> money >> year;
        int d;
        cin >> d;
        for (int i = 0; i < d; i++) {
            cin >> bonds[i].value >> bonds[i].interest;
            bonds[i].value /= 1000;
        }
        
        for (int i = 0; i < year; i++)
            money += func(money, d);

        cout << money << endl;
    }

    return 0;
}

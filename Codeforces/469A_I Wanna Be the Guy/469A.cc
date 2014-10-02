#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[101] = {0};

    for (int t = 0; t < 2; t++) {
        int p;
        cin >> p;
        for (int i = 0; i < p; i++) {
            int var;
            cin >> var;
            a[var] = 1;
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0)
            flag = false;
    }

    if (flag)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;

    return 0;
}


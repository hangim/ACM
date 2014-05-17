#include <iostream>

using namespace std;

int main() {

    /*
        10-man yen == 100000
    */
    int money = 1e5;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        money *= 1.05;

        /*
            nearest sen == nearest 1000
        */
        int var = money % 1000;
        if (var != 0)
            money += 1000 - var;
    }

    cout << money << endl;

    return 0;
}

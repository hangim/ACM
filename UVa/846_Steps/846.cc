#include <iostream>

using namespace std;

int main() {

    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        int i = 0;
        int t = 0;
        if (x == y) {
            cout << 0 << endl;
            continue;
        }

        y -= x;
        x = 0;
        while (true) {
            i++;

            t++;
            x += i;
            if (x >= y) {
                cout << t << endl;
                break;
            }

            t++;
            x += i;
            if (x >= y) {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}

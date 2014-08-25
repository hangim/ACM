#include <iostream>

using namespace std;

int main() {
    int n = 800;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i + i * j << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i + i * j << " ";
        }
        cout << endl;
    }

    return 0;
}

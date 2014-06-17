#include <iostream>

using namespace std;

int main() {

    int n;
    
    while (cin >> n) {
        if (n == 0)
            break;

        int sum = 0;
        int var;
        for (int i = 0; i < n; i++) {
            cin >> var;
            sum += var * var;
        }

        cout << sum << endl;
    
    }
    
    return 0;
}


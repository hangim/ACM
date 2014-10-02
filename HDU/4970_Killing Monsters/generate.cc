#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int n = rand() % 100000 + 1;
    int m = rand() % 100000 + 1;
    cout << n << endl << m << endl;

    for (int i = 0; i < m; i++) {
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        int d = rand() % 1000 + 1;
        if (l > r)
            swap(l, r);
        cout << l << " " << r << " " << d << endl;
    }

    int k = rand() % 100000 + 1;
    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << rand() + 1 << " " << rand() % n + 1 << endl;

    cout << 0 << endl;
    return 0;
}


#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    cout << 1 << endl;
    int n;
    n = rand() % 30 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << rand() % 100000 + 1 << (i == n-1 ? "" : " ");
    cout << endl;

    return 0;
}


#include <iostream>
#include <cstring>
#include <cmath>

#define MAXSIZE 500001

using namespace std;

int m[MAXSIZE];

void init() {
    memset(m, 0, sizeof(m));
    int var = MAXSIZE / 2 + 1;
    for (int i = 1; i < var; i++) {
        for (int j = 2 * i; j < MAXSIZE; j += i)
            m[j] += i;
    }
}

int main() {

    ios::sync_with_stdio(false);

    init();

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        cout << m[n] << endl;
    }

    return 0;
}

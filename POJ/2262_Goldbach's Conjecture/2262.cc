#include <iostream>
#include <cstring>

using namespace std;

bool prime[1000001];

int main() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }

    int n;
    while (cin >> n and n) {
        for (int i = 3; i <= n; i += 2) {
            if (prime[i] and prime[n-i]) {
                cout << n << " = " << i << " + " << n-i << endl;
                break;
            }
        }
    }

    return 0;
}


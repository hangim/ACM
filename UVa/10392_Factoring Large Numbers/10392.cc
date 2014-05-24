#include <iostream>

using namespace std;

const int maxSize = 1000001;

int * getPrime() {
    int * prime = new int[maxSize];

    for (int i = 0; i < maxSize; i++)
        prime[i] = 1;
    for (int i = 2; i < maxSize / 2 + 1; i++) {
        if (prime[i] == 0)
            continue;

        int j = i;
        while ((j += i) < maxSize)
            prime[j] = 0;
    }

    return prime;
}

int main() {

    int * prime = getPrime();

    long long n;
    while (cin >> n) {
        if (n < 0)
            break;

        for (long long i = 2; i < maxSize and i <= n; i++) {
            while (prime[i] and n % i == 0) {
                cout << "    " << i << endl;
                n /= i;
            }
        }

        if (n > 1)
            cout << "    " << n << endl;
        
        cout << endl;
    }

    return 0;
}

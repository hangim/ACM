#include <iostream>

using namespace std;

int square_sum(int n, int base) {
    int sum = 0;
    int var;
    while (n) {
        var = n % base;
        sum += var * var;
        n /= base;
    }
    return sum;
}

int func(int n, int base) {
    int sum = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i != n / i)
                sum += square_sum(i, base) + square_sum(n / i, base);
            else
                sum += square_sum(i, base);
        }
    }

    return sum;
}

void print(int n, int base) {
    if (n == 0)
        return;

    print(n / base, base);

    if (n % base > 9)
        cout << (char) (n % base - 10 + 'A');
    else
        cout << n % base;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        print(func(n, m), m);
        cout << endl;
    }

    return 0;
}


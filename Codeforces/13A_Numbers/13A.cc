#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int getSum(int num, int base) {
    int sum = 0;
    while (num) {
        sum += num % base;
        num /= base;
    }
    return sum;
}

int main() {
    int a;
    cin >> a;
    int sum = 0;
    for (int i = 2; i < a; i++)
        sum += getSum(a, i);

    int var = gcd(sum, a - 2);
    cout << sum / var << "/" << (a - 2) / var << endl;
}

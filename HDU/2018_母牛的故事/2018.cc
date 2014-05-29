#include <iostream>

using namespace std;

int sum[56];


int main() {

    sum[1] = 1;
    sum[2] = 2;
    sum[3] = 3;
    for (int i = 4; i < 56; i++)
        sum[i] = sum[i-1] + sum[i-3];

    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        
        cout << sum[n] << endl;
    }

    return 0;
}

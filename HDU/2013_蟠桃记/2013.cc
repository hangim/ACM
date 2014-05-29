#include <iostream>

using namespace std;

long long sum[31];

int main() {

    sum[1] = 1;
    for (int i = 2; i < 31; i++)
        sum[i] = (sum[i-1] + 1) * 2;

    int n;
    while (cin >> n) {
    
        cout << sum[n] << endl;

    }

    return 0;
}

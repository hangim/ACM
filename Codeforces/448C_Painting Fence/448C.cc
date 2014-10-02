#include <iostream>

using namespace std;

int a[5001];

int calc(int l, int r, int h) {
    if (l > r)
        return 0;

    int m = l, mn = a[l];
    for (int i = l + 1; i <= r; i++) {
        if (mn > a[i]) {
            m = i;
            mn = a[i];
        }
    }

    return min(r - l + 1, calc(l, m-1, mn) + calc(m+1, r, mn) + mn - h);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << calc(0, n-1, 0) << endl;

    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

int cow[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> cow[i];
    sort(cow, cow + n);
    cout << cow[n / 2] << endl;
    return 0;
}


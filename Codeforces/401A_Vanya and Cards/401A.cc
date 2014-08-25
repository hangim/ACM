#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int var;
        cin >> var;
        sum += var;
    }

    sum = abs(sum);
    int ans = sum / m;
    if (sum % m)
        ans++;

    cout << ans << endl;

    return 0;
}


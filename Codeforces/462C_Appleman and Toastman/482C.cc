#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    sort(v.begin(), v.end());

    long long ans = 0;
    long long k = 2;
    for (int i = 0; i < n; i++) {
        k = k > n ? n : k;
        ans += v[i] * k;
        k++;
    }
    cout << ans << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<long long> v(26);

    long long n, k;
    cin >> n >> k;

    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        v[str[i] - 'A']++;

    sort(v.begin(), v.end(), greater<long long>());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (k > v[i]) {
            k -= v[i];
            ans += v[i] * v[i];
        } else {
            ans += k * k;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}



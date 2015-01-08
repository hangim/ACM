#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    while (cin >> a >> b) {
        vector<int> v(100, 0);

        ++b;
        for (int i = 0; (int) pow(2.0, i) < b; ++i) {
            v[i] += b / (int) pow(2.0, i+1) * (int) pow(2.0, i)
                    + max(0, b % (int) pow(2.0, i+1) - (int) pow(2.0, i));
        }
        //for (int i = 0; i < 10; ++i)
        //    cout << v[i] << " ";
        //cout << endl;
        for (int i = 0; (int) pow(2.0, i) < a; ++i) {
            v[i] -= a /  (int) pow(2.0, i+1) * (int) pow(2.0, i)
                    + max(0, a % (int) pow(2.0, i+1) - (int) pow(2.0, i));
        }
        //for (int i = 0; i < 10; ++i)
        //    cout << v[i] << " ";
        //cout << endl << endl;

        long long ans = 0, tmp = 0;
        for (int i = 0; i != v.size(); ++i) {
            //cout << (v[i] + tmp) / 2 << endl;
            ans += (v[i] + tmp) / 2;
            tmp = (v[i] + tmp) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}


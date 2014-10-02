#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n+2);
    v[0] = INT_MIN;
    v[n+1] = INT_MAX;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int l = 0, r = n+1;
    while (l <= n and v[l] < v[l+1])
        l++;
    while (r >= 1 and v[r] > v[r-1])
        r--;

    if (l >= r)
        cout << "yes" << endl << 1 << " " << 1 << endl;
    else if (v[l] > v[r+1] or v[r] < v[l-1])
        cout << "no" << endl;
    else {
        bool flag = true;
        for (int i = l; flag and i < r; i++) {
            if (v[i] < v[i+1])
                flag = false;
        }
        if (flag)
            cout << "yes" << endl << l << " " << r << endl;
        else
            cout << "no" << endl;
    }
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long a, b, c;

long long f(int x) {
    int t = 0;
    while (x) {
        t += x % 10;
        x /= 10;
    }
    return b * (long long)(pow(t, a) + 1e-9) + c;
}

int main() {
    cin >> a >> b >> c;
    vector<long long> v;
    for (int i = 1; i <= 81; i++) {
        long long var = b * (long long)(pow(i, a) + 1e-9) + c;
        if (var > 0LL and var < 1000000000LL and var == f(var))
            v.push_back(var);
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    if (v.size() > 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i == v.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }

    return 0;
}


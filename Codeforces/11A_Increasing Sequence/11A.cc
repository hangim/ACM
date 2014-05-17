#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n, d;
    cin >> n >> d;

    long long last, now;
    cin >> last;

    int count = 0;
    for (int i = 1; i < n; i++) {
        cin >> now;
        if (now <= last) {
            int var = ceil((last + 0.1 - now) / d);
            now += d * var;
            count += var;
        }
        last = now;
    }

    cout << count << endl;

}

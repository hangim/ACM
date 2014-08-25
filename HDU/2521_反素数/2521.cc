#include <iostream>

using namespace std;

const int MAXN = 5000;

int num[MAXN+1] = {0};

void init() {
    for (int i = 1; i <= MAXN; i++) {
        for (int k = i; k <= MAXN; k += i)
            num[k]++;
    }
}

int main() {
    init();

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int ans = a;
        for (int i = a; i <= b; i++) {
            if (num[i] > num[ans])
                ans = i;
        }
        cout << ans << endl;
    }

    return 0;
}


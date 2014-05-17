#include <iostream>

using namespace std;

void init(int *m) {
    m[1] = 0;
    m[2] = 1;
    for (int i = 3; i <= 1000000; i += 2)
        m[i] = 1;

    for (int i = 3; i <= 1000; i += 2) {
        if (m[i] == 0)
            continue;
        for (int j = 2; i * j <= 1000000; j++)
            m[i * j] = 0;
    }

    for (int i = 3; i <= 1000000; i++)
        m[i] += m[i-1];
}

int main() {

    int *memo = new int[1000001];
    init(memo);

    int n;
    while (cin >> n) {
        cout << memo[n] << endl;
    }

    return 0;
}

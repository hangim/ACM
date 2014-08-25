#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num[4] = {1, 6, 8, 9};
    while (next_permutation(num, num + 4)) {
        int var = 0, rem = 0;
        for (int i = 0; i < 4; i++) {
            var = var * 10 + num[i];
            rem = (rem * 10 + num[i]) % 7;
        }
        cout << var << "\t" << rem << endl;
    }

    return 0;
}


#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int rsu[1010];

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        memset(rsu, 0, sizeof(rsu));

        string str1, str2;
        cin >> str1 >> str2;

        for (int i = str1.size() - 1, j = 0; i >= 0; --i, ++j)
            rsu[j] = str1[i] - '0';
        for (int i = str2.size() - 1, j = 0; i >= 0; --i, ++j)
            rsu[j] += str2[i] - '0';

        int pos = max(str1.length(), str2.length()) + 1;

        int rem = 0;
        for (int i = 0; i != pos; ++i) {
            rem = rsu[i] + rem;
            rsu[i] = rem % 10;
            rem /= 10;
        }
        
        while (pos > 0 and rsu[pos] == 0)
            --pos;

        if (k != 1)
            cout << endl;
        cout << "Case " << k << ":" << endl;
        cout << str1 << " + " << str2 << " = ";
        for (int i = pos; i >= 0; --i)
            cout << rsu[i];
        cout << endl;
    }

    return 0;
}


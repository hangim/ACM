#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXSIZE 300

int num[MAXSIZE / 2], rsu[MAXSIZE], tmp[MAXSIZE];

void pow(int exp) {
    memset(rsu, 0, sizeof(rsu));
    memcpy(rsu, num, sizeof(num));
    
    while (--exp) {
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < MAXSIZE / 2; i++)
            for (int j = 0; j < MAXSIZE / 2; j++)
                tmp[i + j] += rsu[i] * num[j];

        // 进位
        int var = 0;
        for (int i = 0; i < MAXSIZE; i++) {
            var += tmp[i];
            tmp[i] = var % 10;
            var /= 10;
        }

        memcpy(rsu, tmp, sizeof(tmp));
    }
}

int main() {
    
    string var;
    int exp;
    while (cin >> var >> exp) {

        int len = var.length();
        int index = 0, precision = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (var[i] != '.')
                num[index++] = var[i] - '0';
            else
                precision = len - 1 - i;
        }

        pow(exp);

        int leadIndex, trialIndex;
        for (leadIndex = MAXSIZE - 1; rsu[leadIndex] == 0; leadIndex--)
            ;
        leadIndex = max(leadIndex, precision * exp - 1);

        for (trialIndex = 0; rsu[trialIndex] == 0; trialIndex++)
            ;

        for (int i = leadIndex; i >= trialIndex; i--) {
            if (i + 1 == exp * precision)
                cout << ".";
            cout << rsu[i];
        }
        cout << endl;
    }

    return 0;
}

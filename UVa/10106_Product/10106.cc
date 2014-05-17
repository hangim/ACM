#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int num1[256], num2[256], rsu[512];

int main() {

    string var1, var2;
    int len1, len2, len3;
    while (cin >> var1 >> var2) {
        // 初始化
        len1 = var1.length();
        len2 = var2.length();
        for (int i = 0; i < len1; i++)
            num1[i] = var1[len1 - 1 - i] - '0';
        for (int i = 0; i < len2; i++)
            num2[i] = var2[len2 - 1 - i] - '0';

        // 相乘
        memset(rsu, 0, sizeof(rsu));
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++)
                rsu[i + j] += num1[i] * num2[j];
        }
        
        // 处理进位
        int var = 0;
        for (int i = 0; i < 512; i++) {
            rsu[i] += var;
            var = rsu[i] / 10;
            rsu[i] = rsu[i] % 10;
        }

        // 输出
        for (len3 = 511; len3 > 0 and rsu[len3] == 0; len3--)
            ;
        for (int i = len3; i >= 0; i--)
            cout << rsu[i];
        cout << endl;
    }

    return 0;
}

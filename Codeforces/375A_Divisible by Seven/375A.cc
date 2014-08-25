#include <iostream>
#include <string>

using namespace std;

int main() {
    int rem_num[7] = {1869, 1896, 1986, 1698, 6198, 6918, 1968};

    string str;
    while (cin >> str) {
        int cnt[10] = {0};
        cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
        for (int i = 0; i < str.size(); i++)
            cnt[str[i]-'0']++;    
        
        int rem = 0;
        for (int i = 1; i <= 9; i++) {
            while (cnt[i]--) {
                cout << i;
                rem = (rem * 10 + i) % 7;
            }
        }
        cout << rem_num[rem * 10000 % 7];
        while (cnt[0]--)
            cout << 0;
        cout << endl;
    }

    return 0;
}


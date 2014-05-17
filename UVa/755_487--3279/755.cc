#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int getDigit(char c) {
    if (c >= '0' and c <= '9')
        return c - '0';

    if (c >= 'A' and c <= 'O')
        return (c - 'A') / 3 + 2;
    if (c == 'P' or c == 'R' or c == 'S')
        return 7;
    return (c - 'T') / 3 + 8;
}

int main() {

    int k;
    cin >> k;
    while (k--) {
    
        int n;
        cin >> n;
        int *phone = new int[n];
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            phone[i] = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == '-')
                    continue;
                phone[i] = phone[i] * 10 + getDigit(str[j]);
            }
        }

        sort(phone, phone + n);

        int i = 0, j;
        bool flag = false;
        while (i < n) {
            j = i + 1;
            while (j < n and phone[i] == phone[j])
                j++;
            if (j - i > 1) {
                flag = true;
                cout << setw(3) << setfill('0') << phone[i] / 10000 << "-" 
                     << setw(4) << setfill('0') << phone[i] % 10000 << " "
                     << j - i << endl;
            }
            i = j;
        }
        if (not flag)
            cout << "No duplicates." << endl;
        if (k)
            cout << endl;
    }
    
    return 0;
}

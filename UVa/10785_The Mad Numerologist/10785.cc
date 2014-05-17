#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string consonant = "JSBKTCLDMVNWFXGPYHQZR";
    string vowels = "AUEOI";
    
    int k;
    cin >> k;
    int index = 1;
    while (k--) {
        int n;
        cin >> n;
        cout << "Case " << index++ << ": ";
        int i = 0, j = 0;
        
        string str1;
        string str2;
        for (int q = 0; q < n; q++) {
            if (q % 2 == 0)
                str1 += vowels[i++ / 21];
            else
                str2 += consonant[j++ / 5];
        }

        int len1 = str1.length(), len2 = str2.length();
        int len = len1 > len2 ? len1 : len2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for (int q = 0; q < len; q++) {
            if (q < len1)
                cout << str1[q];
            if (q < len2)
                cout << str2[q];
        }
        cout << endl;
    }

    return 0;
}


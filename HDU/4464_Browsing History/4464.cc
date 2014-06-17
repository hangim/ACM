#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int index = 1;

    while (cin >> n) {
        int maxValue = 0;
        string str;
        
        for (int i = 0; i < n; i++) {
            cin >> str;
            int tmpValue = 0;
        
            for (string::iterator it = str.begin(); it != str.end(); it++) {
                tmpValue += (int) *it;
            }
            
            maxValue = maxValue >= tmpValue ? maxValue : tmpValue;
        }

        cout << "Case " << index++ << ": " << maxValue << endl;
    }

    return 0;
}


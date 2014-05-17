#include <iostream>
#include <string>

using namespace std;

int m[11] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0};

int main() {

    string str;
    while (getline(cin, str)) {
        int var = 0;
        for (int i = 0; i < 11; i++)
            if (str[i] == 'o')
                var += m[i];
        
        if (var != 0)
            cout << (char) var;
    }

    return 0;
}

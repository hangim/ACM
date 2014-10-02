#include <iostream>
#include <string>

using namespace std;

int main() {
    int len;
    cin >> len;

    string str;
    cin >> str;
    int ans;
    for (ans = 0; ans != str.size() and str[ans] == '1'; ans++)
        ;

    cout << min(ans + 1, len) << endl;

    return 0;
}


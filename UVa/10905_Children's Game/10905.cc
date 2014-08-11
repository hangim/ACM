#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    while (cin >> n and n) {
        string *s = new string[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        sort(s, s + n, cmp);

        for (int i = 0; i < n; i++)
            cout << s[i];
        cout << endl;
    }

}

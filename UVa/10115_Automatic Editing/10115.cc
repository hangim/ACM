#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        cin.get();
        if (n == 0)
            break;

        string *find = new string[n];
        string *replaceBy = new string[n];

        for (int i = 0; i < n; i++) {
            getline(cin, find[i]);
            getline(cin, replaceBy[i]);
        }

        string str;
        getline(cin, str);

        for (int i = 0; i < n; i++) {
            int pos;
            while ((pos = str.find(find[i])) != str.npos) {
                str.replace(pos, find[i].length(), replaceBy[i]);
            }
        }

        cout << str << endl;
    }

    return 0;
}

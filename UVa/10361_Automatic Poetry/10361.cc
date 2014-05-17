#include <iostream>
#include <string>

using namespace std;

int main() {

    int t;
    cin >> t;
    cin.get();

    while (t--) {
        string str;
        string var;
        
        getline(cin, str);
        getline(cin, var);

        int len = str.length();
        int index[4], k = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '<' or str[i] == '>') {
                index[k++] = i;
                continue;
            }

            cout << str[i];
        }
        
        cout << endl << var.substr(0, var.find("..."));
        
        if (index[3] - index[2] - 1 > 0)
            cout << str.substr(index[2] + 1, index[3] - index[2] - 1);
        if (index[2] - index[1] - 1 > 0)
             cout << str.substr(index[1] + 1, index[2] - index[1] - 1);
        if (index[1] - index[0] - 1 > 0)
             cout << str.substr(index[0] + 1, index[1] - index[0] - 1);
        cout << str.substr(index[3] + 1) << endl;

    }

    return 0;

}

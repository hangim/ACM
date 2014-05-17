#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isRearranged(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {

    vector<string> v;

    string var;
    while (cin >> var) {
        if (var == "#")
            break;

        v.push_back(var);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        bool flag = true;
        for (int j = 0; j < v.size(); j++) {
            if (i == j)
                continue;
            if (isRearranged(v[i], v[j])) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << v[i] << endl;
    }

    return 0;
}

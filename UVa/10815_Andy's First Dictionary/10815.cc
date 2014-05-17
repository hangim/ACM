#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iterator>

using namespace std;

int main() {

    vector<string> v;

    string str;
    char var;
    while (cin.get(var)) {
        if (isalpha(var)) {
            str += var;
        } else {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (str.length() > 0 and find(v.begin(), v.end(), str) == v.end())
                v.push_back(str);
            str = "";
        }
    }
    
    // last word
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (str.length() > 0 and find(v.begin(), v.end(), str) == v.end())
        v.push_back(str);
    
    sort(v.begin(), v.end());
    
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}

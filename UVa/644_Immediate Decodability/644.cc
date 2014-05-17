#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string huffman(vector<string> v) {
    int len = v.end() - v.begin();
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++) {
            if (i == j)
                continue;
            if (v[j].find(v[i]) == 0)
                return "not ";
        }
    return "";
}

int main() {
    
    string str;
    vector<string> v;
    int index = 1;
    while (cin >> str) {
        if (str == "9") {
            cout << "Set " << index++ << " is " 
                 << huffman(v) << "immediately decodable" << endl;
            v.clear();
        } else {
            v.push_back(str);
        }
    }

    return 0;
}

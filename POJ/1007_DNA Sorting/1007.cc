//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int number;
    string str;
    
    Node(string &str) {
        this->str = str;
        number = 0;
        for (int i = 0; i != str.length(); ++i) {
            for (int j = i + 1; j != str.length(); ++j) {
                if (str[i] > str[j])
                    ++number;
            }
        }
    }

    bool operator < (const Node &o) const {
        return number < o.number;
    }
};

int main () {
    int n, m;
    cin >> n >> m;
    vector<Node> v;
    for (int i = 0; i != m; ++i) {
        string str;
        cin >> str;
        v.push_back(Node(str));
    }

    stable_sort(v.begin(), v.end());
    for (int i = 0; i != v.size(); ++i) {
        cout << v[i].str << endl;
    }

    return 0;
}

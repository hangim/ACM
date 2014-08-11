// std=c++11

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string str;
    cin >> str;

    deque<char> q;
    for (char i : str) {
        if (not q.empty() and q.back() == i)
            q.pop_back();
        else
            q.push_back(i);
    }

    while (not q.empty()) {
        cout << q.front();
        q.pop_front();
    }
    cout << endl;

    return 0;
}

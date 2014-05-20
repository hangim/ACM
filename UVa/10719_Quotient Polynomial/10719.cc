// g++ 10719.cc -std=c++11

#include <iostream>
#include <string>

using namespace std;

int main() {

    int k;
    int last, now;
    while (cin >> k) {
        string str = "q(x):";
        cin >> last;
        while (cin.get() != '\n') {
            cin >> now;
            str += " " + to_string(last);
            last = now - last * (-k);
        }

        cout << str << endl;
        cout << "r = " << last << endl << endl;
    }

    return 0;
}

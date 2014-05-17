#include <iostream>
#include <string>

using namespace std;

int tail = 0;
int rsu[110] = {0};

void add(string str) {
    for (int i = str.length() - 1, j = 0; i >= 0; i--, j++) {
        rsu[j] += str[i] - '0';
    }
    int var = 0;
    for (int i = 0; i < 110; i++) {
        var += rsu[i];
        rsu[i] = var % 10;
        var /= 10;
    }
}

int main() {
    
    string str;
    while (cin >> str) {
        if (str == "0") {
            break;
        }
        add(str);
    }

    int tail;
    for (tail = 109; tail >= 0 and rsu[tail] == 0; tail--)
        ;

    if (tail == -1) {
        cout << 0 << endl;
    } else {
        for (int i = tail; i >= 0; i--)
            cout << rsu[i];
        cout << endl;
    }

    return 0;
}

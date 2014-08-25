#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        cin.get();
        string str = "";
        for (int i = 0; i < n; i++) {
            string tmp;
            getline(cin, tmp);
            str += tmp;
        }

        long long ans = 1;
        for (int i = 0; i < str.size(); i++) {
            int num = 0;
            int j;
            if (str[i] == '{') {
                for (j = i + 1; str[j] != '}'; j++) {
                    if (str[j] == '|')
                        num++;
                }
                ans *= num + 1;
                i = j;
            } else if (str[i] == '$') {
                for (j = i + 1; str[j] != '$'; j++) {
                    if (str[j] == ' ') {
                        num++;
                    } else {
                        ans *= num + 1;
                        num = 0;
                        if (ans > 100000)
                            break;
                    }
                }
                ans *= num + 1;
                i = j;
            }

            if (ans > 100000)
                break;
        }

        if (ans <= 100000)
            cout << ans << endl;
        else
            cout << "doge" << endl;
    }

    return 0;
}


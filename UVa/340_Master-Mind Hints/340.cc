#include <iostream>

using namespace std;

int main() {

    int n, index = 1;
    
    while (cin >> n) {
        if (n == 0)
            break;
        cout << "Game " << index++ << ":" << endl;

        int *secret = new int[n];
        for (int i = 0; i < n; i++)
            cin >> secret[i];

        while (true) {
            int *guess = new int[n];
            bool *vis = new bool[n];
            int strong = 0, weak = 0;

            bool flag = false;
            for (int i = 0; i < n; i++) {
                cin >> guess[i];
                if (guess[i] == secret[i]) {
                    strong++;
                    guess[i] = -1;
                    vis[i] = true;
                    flag = true;
                } else {
                    flag |= guess[i];
                    vis[i] = false;
                }
            }

            if (not flag)
                break;

            for (int i = 0; i < n; i++) {
                if (guess[i] == -1)
                    continue;
                for (int j = 0; j < n; j++) {
                    if (vis[j])
                        continue;

                    if (guess[i] == secret[j]) {
                        vis[j] = true;
                        guess[i] = -1;
                        weak++;
                    }
                }
            }
            cout << "    (" << strong << "," << weak << ")" << endl; 
        }

    }

    return 0;
}

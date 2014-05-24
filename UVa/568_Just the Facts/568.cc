#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
            while (ans % 10 == 0)
                ans /= 10;
            ans %= 100000;
        }
        
        cout << setw(5) << setiosflags(ios::right) << n
             << " -> " << ans % 10 << endl;
    }
    
    return 0;
}

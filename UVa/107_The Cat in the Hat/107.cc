#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int h, m;
    while (cin >> h >> m) {
        if (h == 0 or m == 0)
            break;

        double n = 1;
        while (abs(log(n) / log(n + 1) - log(m) / log(h)) > 1e-10)
            n++;
        
        int k = round(log(h) / log(n + 1));

        int notWorking;
        if (n == 1)
            notWorking = k;
        else
            notWorking = round((1 - pow(n, k)) / (1 - n));

        int totalHeight = round(h * (1 - pow(n / (n + 1), k + 1)) * (n + 1));
        
        cout << notWorking << " " << totalHeight << endl;
    }

    return 0;
}

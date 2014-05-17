#include <iostream>

using namespace std;

int main() {
    int h, u, d, f;
    while (cin >> h >> u >> d >> f) {
        if (h == 0)
            break;
        int i = 0;
        double now = 0;
        double step = u;
        while (true) {
            i++;
            if (step > 0) {
                now += step;
                step = step - u * f / 100.0;
            }
            if (now > h) {
                cout << "success on day " << i << endl;
                break;
            }
            now -= d;
            if (now < 0) {
                cout << "failure on day " << i << endl;
                break;
            }
        }
    }
    return 0;
}

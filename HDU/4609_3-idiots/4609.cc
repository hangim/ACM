#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Complex;

const double pi = acos(-1.0);

void change(Complex y[], int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j)
            swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
    }
}

void fft(Complex y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on * 2 * pi / h), sin(-on * 2 * pi / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++)
            y[i] /= len;
}

int a[100000 + 10];
Complex x[(1 << 18) + 10];
long long sum[200000 + 10];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int maxx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            maxx = max(maxx, a[i]);
        }
        int len = 1;
        while (len <= maxx * 2)
            len <<= 1;
        for (int i = 0; i < len; ++i)
            x[i] = 0;
        for (int i = 0; i < n; ++i)
            x[a[i]] += 1;

        fft(x, len, 1);
        for (int i = 0; i < len; ++i)
            x[i] *= x[i];
        fft(x, len, -1);
        
        for (int i = 0; i < n; ++i)
            x[a[i] * 2] -= 1;
        for (int i = 0; i < len; ++i)
            x[i] /= 2;

        sum[0] = 0;
        for (int i = 1; i <= 2 * maxx; ++i)
            sum[i] = sum[i-1] + (x[i].real() + 1e-6);

        long long ans = 0;
        sort(a, a + n);
        for (int i = 0; i < n; ++i)
            ans += sum[2 * maxx] - sum[a[i]] - (long long)i * (n - 1 - i) - (long long)(n - 1 - i) * (n - 1 - i - 1) / 2 - (n - 1);
        printf("%.7f\n", 1. * ans / (1. * n * (n-1) * (n-2) / 6));
    }
    return 0;
}


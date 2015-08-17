#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

struct Complex {
    double r, i;
    Complex(double _r = 0.0, double _i = 0.0) {
        r = _r;
        i = _i;
    }
    Complex operator + (const Complex &b) {
        return Complex(r + b.r, i + b.i);
    }
    Complex operator - (const Complex &b) {
        return Complex(r - b.r, i - b.i);
    }
    Complex operator * (const Complex &b) {
        return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
    }
};

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
            y[i].r /= len;
}

const int maxn = 65536;
Complex x1[maxn * 2 + 10], x2[maxn * 2 + 10];
char s1[maxn], s2[maxn];
int sum[maxn * 2 + 10];

int main() {
    while (scanf("%s %s", s1, s2) == 2) {
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int len = 1;
        while (len < len1 * 2 or len < len2 * 2)
            len <<= 1;
        for (int i = 0; i < len1; i++)
            x1[i] = Complex(s1[len1 - 1 - i] - '0', 0);
        for (int i = len1; i < len; i++)
            x1[i] = Complex(0, 0);
        for (int i = 0; i < len2; i++)
            x2[i] = Complex(s2[len2 - 1 - i] - '0', 0);
        for (int i = len2; i < len; i++)
            x2[i] = Complex(0, 0);

        fft(x1, len, 1);
        fft(x2, len, 1);
        for (int i = 0; i < len; i++)
            x1[i] = x1[i] * x2[i];
        fft(x1, len, -1);

        sum[0] = 0;
        for (int i = 0; i < len; i++) {
            sum[i] += (int) (x1[i].r + 0.5);
            sum[i+1] = sum[i] / 10;
            sum[i] %= 10;
        }

        len = len1 + len2 - 1;
        while (len > 0 and sum[len] == 0)
            len--;
        for (int i = len; i >= 0; i--)
            printf("%c", sum[i] + '0');
        puts("");
    }
    return 0;
}


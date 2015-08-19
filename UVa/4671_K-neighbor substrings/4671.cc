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


const int maxn = 100000;
unsigned long long xp[maxn + 10];
unsigned long long H[maxn + 10];
unsigned long long seed = 23333;

void init_hash(char *s, int len) {
    xp[0] = 1;
    H[0] = s[0] - 'a' + 1;
    for (int i = 1; i < len; ++i) {
        xp[i] = xp[i-1] * seed;
        H[i] = H[i-1] * seed + s[i] - 'a' + 1;
    }
}

unsigned long long ask_hash(int l, int r) {
    return l == 0 ? H[r] : H[r] - H[l-1] * xp[r-l+1];
}


char sa[maxn + 10], sb[maxn + 10];
Complex aa[(1 << 18) + 10], bb[(1 << 18) + 10];
int cnt[maxn + 10];

int main() {
    int k;
    int cs = 1;
    while (scanf("%d", &k) != EOF) {
        if (k == -1)
            break;
        printf("Case %d: ", cs++);
        
        scanf("%s %s", sa, sb);
        int la = strlen(sa), lb = strlen(sb);
        int len = 1;
        while (len < la + lb)
            len <<= 1;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < la; ++i)
            aa[i] = 'b' - sa[i];
        for (int i = la; i < len; ++i)
            aa[i] = 0;
        for (int i = 0; i < lb; ++i)
            bb[i] = 'b' - sb[lb-i-1];
        for (int i = lb; i < len; ++i)
            bb[i] = 0;
        fft(aa, len, 1);
        fft(bb, len, 1);
        for (int i = 0; i < len; ++i)
            aa[i] *= bb[i];
        fft(aa, len, -1);
        for (int i = 0; i < len; ++i)
            cnt[i] += aa[i].real() + 0.5;

        for (int i = 0; i < la; ++i)
            aa[i] = sa[i] - 'a';
        for (int i = la; i < len; ++i)
            aa[i] = 0;
        for (int i = 0; i < lb; ++i)
            bb[i] = sb[lb-i-1] - 'a';
        for (int i = lb; i < len; ++i)
            bb[i] = 0;
        fft(aa, len, 1);
        fft(bb, len, 1);
        for (int i = 0; i < len; ++i)
            aa[i] *= bb[i];
        fft(aa, len, -1);
        for (int i = 0; i < len; ++i)
            cnt[i] += aa[i].real() + 0.5;

        init_hash(sa, la);
        set<unsigned long long> s;
        for (int i = 0; i + lb <= la; ++i) {
            if (lb - cnt[i+lb-1] <= k)
                s.insert(ask_hash(i, i + lb - 1));
        }
        printf("%d\n", (int) s.size());
    }
    return 0;
}


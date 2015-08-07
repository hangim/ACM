#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    int p, q;
    Fraction(int P) : p(P), q(1) {}
    Fraction(int P, int Q) : p(P), q(Q) {
        simplify();
    }
    void simplify() {
        int g = gcd(p, q);
        p /= g;
        q /= g;
    }
    Fraction operator + (const Fraction &f) const {
        return Fraction(p * f.q + q * f.p, q * f.q);
    }
    Fraction operator - (const Fraction &f) const {
        return Fraction(p * f.q - q * f.p, q * f.q);
    }
    Fraction operator * (const Fraction &f) const {
        return Fraction(p * f.p, q * f.q);
    }
    Fraction operator / (const Fraction &f) const {
        return Fraction(p * f.q, q * f.p);
    }
    Fraction operator * (int n) {
        return Fraction(p * n, q);
    }
    Fraction operator % (int m) const {
        return Fraction(p % (m * q), q);
    }
    bool operator < (const Fraction &f) const {
        return p * f.q < f.p * q;
    }
    bool operator == (int n) const {
        return p == n * q;
    }
    bool operator <= (int n) const {
        return p <= n * q;
    }
    bool operator >= (int n) const {
        return p >= n * q;
    }
};

int read() {
    int H, M, S;
    scanf("%d:%d:%d", &H, &M, &S);
    return H * 3600 + M * 60 + S;
}

void output(Fraction &f) {
    int s = f.p / f.q;
    printf("%02d:%02d:%02d", s / 3600, s / 60 % 60, s % 60);
    if (f.p % f.q)
        printf(" %d/%d", f.p - s * f.q, f.q);
    puts("");
}

void solve() {
    int sym = read();
    int from = read();
    int to = read();

    Fraction hour(360, 12 * 3600);
    Fraction minu(360, 3600);
    vector<Fraction> ans;

    Fraction axis = hour * sym;
    for (int i = 0; i <= 12; ++i) {
        Fraction current = hour * i * 3600;
        Fraction x = (axis * 2 - current) / (hour + minu);
        x = (x + Fraction(i * 3600)) % (12 * 3600);
        if (x >= from and x <= to)
            ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i)
        output(ans[i]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case %d: ", cs);
        solve();
    }
    return 0;
}


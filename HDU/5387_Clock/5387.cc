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
        int g = gcd(abs(p), abs(q));
        if (g == 0) return;
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

void output(Fraction A) {
    if (A.p < 0)
        output(Fraction(-1 * A.p, A.q));
    else if (A.p > A.q * 180)
        output(Fraction(A.q * 360 - A.p, A.q));
    else {
        if (A.p % A.q)
            printf("%d/%d ", A.p, A.q);
        else
            printf("%d ", A.p);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        Fraction S = Fraction(360, 60) * ss;
        Fraction M = (Fraction(1, 60) * ss + mm) * Fraction(360, 60);
        Fraction H = (Fraction(1, 3600) * ss + Fraction(1, 60) * mm + hh) * Fraction(360, 12);

        output(H - M);
        output(H - S);
        output(M - S);
        puts("");
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

char func(const char c) {
    char A[100] = "_+" "QWERTYUIOP{}" "ASDFGHJKL:\"" "ZXCVBNM<>?"
        "-=" "qwertyuiop[]" "asdfghjkl;'" "zxcvbnm,./"; 
    char B[100] = "{}" "\"<>PYFGCRL?+" "AOEUIDHTNS_" ":QJKXBMWVZ"
        "[]" "',.pyfgcrl/=" "aoeuidhtns-" ";qjkxbmwvz";
    for (int i = 0; i != 100; ++i) {
        if (A[i] == c)
            return B[i];
    }
    return c;
}

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(func(c));
    }
    return 0;
}


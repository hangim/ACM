#include <cstdio>
#include <cstring>

using namespace std;

char s[210];

int main() {
    while (fgets(s, sizeof(s), stdin)) {
        if (strncmp(s, "ENDOFINPUT", 10) == 0)
            break;
        if (strncmp(s, "START", 5) == 0 or strncmp(s, "END", 3) == 0)
            continue;
        int len = strlen(s);
        for (int i = 0; i != len; ++i)
            if (s[i] >= 'A' and s[i] <= 'Z')
                s[i] = 'A' + (s[i] - 'A' - 5 + 26) % 26;
        fputs(s, stdout);
    }
    return 0;
}


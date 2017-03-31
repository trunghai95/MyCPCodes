#include <bits/stdc++.h>

using namespace std;

int a, c;
char s[20] = "0101000011011011";
char t[20] = "................";

int main() {
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &a);
        c = c*2 + a;
    }

    printf("%c\n", s[c]);
    return 0;
}

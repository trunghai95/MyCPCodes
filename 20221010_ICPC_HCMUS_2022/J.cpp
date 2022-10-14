#include <bits/stdc++.h>

using namespace std;

char s[10];
int a[4];

char f(int x, int bit) {
    if ((x >> bit) & 1) {
        return '*';
    }
    return '.';
}

int main() {
    scanf("%s", s);
    for (int i = 0; i < 4; i++) {
        a[i] = s[i] - '0';
    }
    for (int i = 3; i >= 0; i--) {
        printf("%c%c %c%c\n", f(a[0],i), f(a[1],i), f(a[2],i), f(a[3],i));
    }
    return 0;
}
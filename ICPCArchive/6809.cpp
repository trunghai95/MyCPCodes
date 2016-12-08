#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

int test;
ui a, b;
char s[10];

ui convert(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

ui read() {
    scanf("%s", s);
    ui res = 0;
    for (int i = 0; s[i]; ++i) {
        res = res*16 + convert(s[i]);
    }
    return res;
}

ui rot(ui a, int cnt) {
    ui tmp = ((ui(1) << cnt) - 1) & a;
    return (a >> cnt) | (tmp << (32 - cnt));
}

void solve() {
    if (a == b) {
        printf("0 Any\n");
        return;
    }

    for (int i = 1; i <= 17; ++i) {
        if (rot(a, i) == b) {
            if (rot(b, i) == a) {
                printf("%d Any\n", i);
            } else {
                printf("%d Right\n", i);
            }
            return;
        } else if (rot(b, i) == a) {
            printf("%d Left\n", i);
            return;
        }
    }
    printf("Not possible\n");
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        a = read();
        b = read();
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
int n;
char s[MAXN];
bool flag;

void solve() {
    scanf("%d\n%s", &n, s);
    flag = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            printf("+");
        } else {
            if (!flag) {
                printf("-");
            } else {
                printf("+");
            }
            flag = !flag;
        }
    }
    printf("\n");
}

int main() {
    int test;
    scanf("%d", &test);
    while (test --> 0) {
        solve();
    }
    return 0;
}
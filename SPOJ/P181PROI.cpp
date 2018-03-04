#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n;
char s[MAXN+3];

int main() {
    scanf("%d %s", &n, s);
    int res = 0;
    for (int i = 2; i < n; ++i)
    if (s[i-2] == '0' && s[i-1] == '1' && s[i] == '0') {
        ++res;
        s[i] = '1';
    }
    printf("%d\n", res);
    return 0;
}
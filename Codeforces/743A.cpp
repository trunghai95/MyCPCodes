#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, a, b;
char s[MAXN+5];

int main() {
    scanf("%d %d %d %s", &n, &a, &b, s+1);
    printf("%d\n", (s[a] != s[b]));
    return 0;
}

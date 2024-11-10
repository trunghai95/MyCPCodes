#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int n, lo, hi, loPow, hiPow;
char s[MAXN];

int main() {
    scanf("%d\n%s", &n, s);
    lo = 1;
    hi = (1 << n);
    loPow = hiPow = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            lo += loPow;
            loPow *= 2;
        } else {
            hi -= hiPow;
            hiPow *= 2;
        }
    }
    for (int i = lo; i <= hi; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
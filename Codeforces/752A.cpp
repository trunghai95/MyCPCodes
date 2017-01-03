#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    int kk = (k+1) / 2;
    n = (kk-1) / m + 1;
    m = (kk-1) % m + 1;

    printf("%d %d %c\n", n, m, (k&1)?'L':'R');
    return 0;
}

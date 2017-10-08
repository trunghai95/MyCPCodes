#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, x;
bool ck[MAXN+2];

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        ck[a] = true;
    }

    int res = 0;
    for (int i = 0; i < x; ++i) {
        if (!ck[i]) ++res;
    }

    if (ck[x]) ++res;

    printf("%d\n", res);
    return 0;
}

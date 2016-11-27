#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int test, n, a[MAXN+5];
bool ck[MAXN+5];

void proc(int u) {
    while (!ck[u]) {
        ck[u] = true;
        u = a[u];
    }
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        memset(ck, 0, sizeof(ck));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);

        int res = 0;
        for (int i = 1; i <= n; ++i)
        if (!ck[i]) {
            proc(i);
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}

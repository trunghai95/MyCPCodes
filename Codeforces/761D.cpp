#include <bits/stdc++.h>

using namespace std;

struct S {
    int a, b, p, id;
};

bool cmpp(S a, S b) {
    return a.p < b.p;
}

bool cmpid(S a, S b) {
    return a.id < b.id;
}

const int MAXN = 100000;
int n, l, r;
S a[MAXN+2];

int main() {
    scanf("%d %d %d", &n, &l, &r);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].a);
        a[i].id = i;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].p);
    }

    sort(a+1, a+1+n, cmpp);

    a[1].b = l;

    for (int i = 2; i <= n; ++i) {
        a[i].b = max(l, a[i-1].b - a[i-1].a + 1 + a[i].a);
        if (a[i].b > r) {
            printf("-1\n");
            return 0;
        }
    }

    sort(a+1, a+1+n, cmpid);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i].b);
    }
    printf("\n");
    return 0;
}

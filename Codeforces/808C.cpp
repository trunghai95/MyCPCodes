#include <bits/stdc++.h>

using namespace std;

struct Cup {
    int id, a, b;
};

bool cmp(Cup x, Cup y) {
    return x.a < y.a;
}

bool cmp2(Cup x, Cup y) {
    return x.id < y.id;
}

const int MAXN = 100;
int n, w;
Cup a[MAXN+2];

int main() {
    scanf("%d %d", &n, &w);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].a);
        a[i].id = i;
        a[i].b = (a[i].a - 1) / 2 + 1;

        w -= a[i].b;
    }

    if (w < 0) {
        printf("-1\n");
        return 0;
    }

    sort(a+1, a+1+n, cmp);

    for (int i = n; i >= 1 && w > 0; --i) {
        int tmp = min(w, a[i].a - a[i].b);
        a[i].b += tmp;
        w -= tmp;
    }

    if (w) {
        printf("-1\n");
    } else {
        sort(a+1, a+1+n, cmp2);
        for(int i = 1; i <= n; ++i) {
            printf("%d ", a[i].b);
        }

        printf("\n");
    }

    return 0;
}

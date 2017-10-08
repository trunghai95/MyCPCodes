#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, pos0, pos1, sum1;
char s[MAXN+3];

int query(int l, int r) {
    for (int i = 1; i < l; ++i) {
        s[i] = '0';
    }
    for (int i = l; i <= r; ++i) {
        s[i] = '1';
    }
    for (int i = r+1; i <= n; ++i) {
        s[i] = '0';
    }

    printf("? %s\n", s+1);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

void find0(int l, int r, int cnt1) {
    if (cnt1 == 0) {
        pos0 = r;
        return;
    }

    int mid = (l+r-1)/2 + 1;
    int cc = query(mid, r) - sum1;
    int c1 = r - mid + 1;
    c1 = (c1 - cc)/2;

    if (c1 == 0) {
        pos0 = r;
    } else if (c1 == cnt1) {
        pos0 = l;
    } else if (c1 == r - mid + 1) {
        find0(l, mid-1, cnt1 - c1);
    } else {
        find0(mid, r, c1);
    }
}

void find(int l, int r, int cnt1) {
    if (cnt1 == r-l+1) {
        pos1 = r;
        return;
    }

    int mid = (l+r-1)/2 + 1;
    int cc = query(mid, r) - sum1;
    int c1 = r - mid + 1;
    c1 = (c1 - cc)/2;

    if (c1 == 0) {
        pos0 = r;
        find(l, mid - 1, cnt1);
    } else if (c1 == cnt1) {
        pos0 = l;
        find(mid, r, c1);
    } else if (c1 == r - mid + 1 && !pos0) {
        pos1 = r;
        find0(l, mid-1, cnt1 - c1);
    } else {
        find(mid, r, c1);
    }
}

int main() {
    scanf("%d", &n);
    sum1 = query(1,0);
    find(1, n, sum1);
    printf("! %d %d\n", pos0, pos1);
    fflush(stdout);
    return 0;
}

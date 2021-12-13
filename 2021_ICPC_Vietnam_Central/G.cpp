#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, k, it[MAXN*10], x, y, z;
char s[MAXN];

int get(int id, int lo, int hi, int p) {
    if (lo == hi) {
        return it[id];
    }

    int mid = (lo + hi) / 2;
    if (p <= mid) {
        return it[id] + get(id * 2 + 1, lo, mid, p);
    } else {
        return it[id] + get(id * 2 + 2, mid + 1, hi, p);
    }
    
    return -1;
}

void update(int id, int lo, int hi, int l, int r, int val) {
    if (hi < l || lo > r) {
        return;
    }
    if (lo >= l && hi <= r) {
        it[id] += val;
        return;
    }
    int mid = (lo + hi) / 2;
    update(id * 2 + 1, lo, mid, l, r, val);
    update(id * 2 + 2, mid + 1, hi, l, r, val);
}

int main() {
    scanf("%s %d", s, &k);
    n = strlen(s);

    while (k --> 0) {
        scanf("%d %d %d", &x, &y, &z);
        update(0, 0, n-1, y-1, z-1, x);
    }

    for (int i = 0; i < n; i++) {
        // printf("%d\n", get(0, 0, n-1, i));
        s[i] = (s[i] - 'A' + get(0, 0, n-1, i)) % 26 + 'A';
    }

    printf("%s\n", s);
    return 0;
}
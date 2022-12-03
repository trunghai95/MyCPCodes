#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+2;
const int MAXIT = MAXN*4;
int n, q, a[MAXN], l, r;
vector<int> it[MAXIT];

void init(int id, int lo, int hi) {
    if (hi < lo) {
        return;
    }
    if (lo == hi) {
        it[id].push_back(a[lo]);
        return;
    }
    int mid = (lo + hi) / 2;
    int c1 = id*2+1;
    int c2 = id*2+2;
    init(c1, lo, mid);
    init(c2, mid+1, hi);

    int i = 0;
    int j = 0;
    while (i < it[c1].size() && j < it[c2].size()) {
        if (it[c1][i] < it[c2][j]) {
            it[id].push_back(it[c1][i]);
            i++;
        } else {
            it[id].push_back(it[c2][j]);
            j++;
        }
    }
    while (i < it[c1].size()) {
        it[id].push_back(it[c1][i]);
        i++;
    }
    while (j < it[c2].size()) {
        it[id].push_back(it[c2][j]);
        j++;
    }
}

// Number of elements less than val
int cnt(vector<int> &v, int val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

int cnt(int id, int lo, int hi, int l, int r, int val) {
    if (lo > r || hi < l) {
        return 0;
    }

    if (lo >= l && hi <= r) {
        return cnt(it[id], val);
    }

    int mid = (lo + hi) / 2;
    return cnt(id*2+1, lo, mid, l, r, val) + cnt(id*2+2, mid+1, hi, l, r, val);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    init(0, 1, n);

    while (q --> 0) {
        scanf("%d %d", &l, &r);
        int lo = 1;
        int hi = MAXN;
        int bound = (r - l) / 2;
        while (lo < hi) {
            int mid = (lo + hi) / 2 + 1;
            int c = cnt(0, 1, n, l, r, mid);
            if (c > bound) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        printf("%d\n", lo);
    }
    return 0;
}
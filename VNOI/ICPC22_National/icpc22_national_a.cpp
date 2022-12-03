#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int MAXN = 200005;
int n, q, curVer, rk[MAXN];
char c;
vector<pii> dsu[MAXN]; // ver-val

void init() {
    for (int i = 1; i <= n; i++) {
        dsu[i].push_back(pii(0, i));
    }
    curVer = 1;
}

void debug() {
    printf("---debug---\n");
    for (int i = 1; i <= n; i++) {
        printf("dsu %d: ", i);
        for (int j = 0; j < dsu[i].size(); j++) {
            printf("(%d,%d) ", dsu[i][j].first, dsu[i][j].second);
        }
        printf("\n");
    }
    printf("-----------\n");
}

int& get(int x, int version) {
    // debug();
    // printf("Get %d %d ", x, version);
    int lo = 0, hi = dsu[x].size()-1;
    while (lo < hi) {
        // printf("bin1 %d %d\n", lo, hi);
        int mid = (lo + hi) / 2 + 1;
        if (dsu[x][mid].first > version) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
        // printf("bin %d %d\n", lo, hi);
    }
    // printf("--> %d %d\n", lo, dsu[x][lo].second);
    // debug();
    return dsu[x][lo].second;
}

int& getLatest(int x) {
    if (dsu[x].back().first < curVer) {
        dsu[x].push_back(pii(curVer, dsu[x].back().second));
    }
    // debug();
    return dsu[x].back().second;
}

int find(int x, int ver) {
    // printf("find %d %d\n", x, ver);
    int &d = get(x, ver);
    if (d == x) {
        return x;
    }
    return (d = find(d, ver));
}

int findLatest(int x) {
    int &d = getLatest(x);
    if (d == x) {
        return x;
    }
    return (d = findLatest(d));
}

void join(int x, int y) {
    int xs = findLatest(x);
    int ys = findLatest(y);
    if (xs == ys) {
        return;
    }
    if (rk[xs] < rk[ys]) {
        getLatest(xs) = ys;
    } else if (rk[xs] > rk[ys]) {
        getLatest(ys) = xs;
    } else {
        getLatest(ys) = xs;
        rk[xs]++;
    }
}

void add() {
    int x, y;
    scanf("%d %d\n", &x, &y);
    // printf("add %d %d\n", x, y);
    join(x, y);
}

void check() {
    int x, y;
    scanf("%d %d\n", &x, &y);
    // printf("check %d %d\n", x, y);
    if (findLatest(x) == findLatest(y)) {
        printf("Y");
    } else {
        printf("N");
    }
}

void commit() {
    scanf("\n");
    // printf("commit\n");
    curVer++;
}

void query() {
    int x, y, ver;
    scanf("%d %d %d\n", &ver, &x, &y);
    // printf("query %d %d %d\n", ver, x, y);
    if (find(x, ver) == find(y, ver)) {
        printf("Y");
    } else {
        printf("N");
    }
    // ...
}

int main() {
    scanf("%d %d\n", &n, &q);
    init();
    while (q --> 0) {
        scanf("%c", &c);
        switch (c) {
            case 'A':
                add();
                break;
            case '?':
                check();
                break;
            case 'C':
                commit();
                break;
            case 'Q':
                query();
                break;
        }
    }
    printf("\n");
    return 0;
}
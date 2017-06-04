#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, m, p[MAXN+2], a[MAXN+2], b[MAXN+2], ptr[4], x, y;
vector<int> id[4];
bool ck[MAXN+2];

bool cmp(int x, int y) {
    return p[x] < p[y];
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", p+i);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        id[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", b+i);
        if (a[i] != b[i])
            id[b[i]].push_back(i);
    }

    for (int i = 1; i <= 3; ++i) {
        sort(id[i].begin(), id[i].end(), cmp);
    }

    scanf("%d", &m);
    while (m --> 0) {
        scanf("%d", &x);
        if (ptr[x] >= (int)id[x].size()) {
            printf("-1 ");
            continue;
        }
        printf("%d ", p[id[x][ptr[x]]]);
        ck[id[x][ptr[x]]] = true;

        if (a[id[x][ptr[x]]] != x) {
            y = a[id[x][ptr[x]]];
        } else {
            y = b[id[x][ptr[x]]];
        }

        while (ptr[x] < (int)id[x].size() && ck[id[x][ptr[x]]]) {
            ++ptr[x];
        }

        while (ptr[y] < (int)id[y].size() && ck[id[y][ptr[y]]]) {
            ++ptr[y];
        }
    }

    printf("\n");
    return 0;
}

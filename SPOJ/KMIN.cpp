#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAX = 50000;
int n, m, k, a[MAX+5], b[MAX+5], pos[MAX+5];
priority_queue<pii, vector<pii>, greater<pii> > heap;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", b+i);

    sort(b+1, b+1+m);
    for (int i = 1; i <= n; ++i)
        heap.push(pii(a[i] + b[1], i)), pos[i] = 1;

    while (k --> 0 && !heap.empty()) {
        pii u = heap.top(); heap.pop();
        printf("%d\n", u.F);
        if (pos[u.S] < m) {
            heap.push(pii(a[u.S] + b[++pos[u.S]], u.S));
        }
    }

    return 0;
}

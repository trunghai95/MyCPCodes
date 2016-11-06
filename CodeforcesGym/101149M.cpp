#include <bits/stdc++.h>

using namespace std;

int n, eli[1010];
queue<int> q;
char s[10];

bool cmp(int u, int v) {
    printf("? %d %d\n", u, v);
    fflush(stdout);
    scanf("%s", s);
    return s[0] == '<';
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        q.push(i);

    while (q.size() >= 2) {
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();

        if (cmp(u, v)) {
            q.push(v);
            eli[u] = v;
        } else {
            q.push(u);
            eli[v] = u;
        }
    }

    int res = -1;
    for (int i = 1; i <= n; ++i)
    if (eli[i] == q.front()) {
        res = i;
        break;
    }

    for (int i = res + 1; i <= n; ++i)
    if (eli[i] == q.front() && cmp(res, i))
        res = i;

    printf("! %d\n", res);
    return 0;
}

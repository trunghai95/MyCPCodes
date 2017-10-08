#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, l[MAXN+2], r[MAXN+2];
queue<int> q;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", l+i, r+i);
        if (l[i] == 0) q.push(i);
    }

    int cur = q.front();
    q.pop();

    while (!q.empty()) {
        while (r[cur] != 0) {
            cur = r[cur];
        }

        r[cur] = q.front();
        l[q.front()] = cur;
        q.pop();
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}

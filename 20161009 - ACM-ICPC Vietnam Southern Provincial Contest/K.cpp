#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

struct cmp {
    bool operator()(pii x, pii y) {
        if (x.F == y.F) {
            return x.S > y.S;
        }
        return x.F > y.F;
    }
};

int lcm(int x, int y) {
    int g = __gcd(x, y);
    return x / g * y;
}

int n, m, a[1010];
int mx = 1;
priority_queue<pii, vector<pii>, cmp> heap;

int count(int time) {
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        res += time / a[i] + 1;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        scanf("%d", a+i);
        mx = lcm(mx, a[i]);
    }

    n = (n - 1) % count(mx - 1) + 1;
    if (n <= m) {
        printf("%d\n", n);
        return 0;
    }

    int lef = 0, rig = mx - 1;

    while (lef < rig) {
        int mid = (lef + rig) / 2 + 1;
        if (count(mid) >= n) {
            rig = mid - 1;
        } else {
            lef = mid;
        }
    }

    n -= count(lef);

    for (int i = 1; i <= m; ++i) {
        heap.push(pii((lef / a[i] + 1) * a[i], i));
    }

    for (int i = 1; i < n; ++i) {
        pii u = heap.top();
        heap.pop();
        heap.push(pii(u.F + a[u.S], u.S));
    }

    pii u = heap.top();
    printf("%d\n", u.S);
    return 0;
}

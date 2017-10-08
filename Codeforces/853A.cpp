#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300000;
int n, k, res[MAXN+2];
ll c[MAXN+2], sum;

struct cmp {
    bool operator()(int x, int y) {
        return c[x] < c[y];
    }
};

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", c+i);
    }

    priority_queue<int, vector<int>, cmp> heap;

    for (int i = 1; i <= k; ++i) {
        heap.push(i);
    }

    for (int i = k+1; i <= k+n; ++i) {
        if (i <= n) {
            heap.push(i);
        }

        int a = heap.top();
        heap.pop();

        res[a] = i;
        sum += c[a] * (i - a);
    }

    printf("%lld\n", sum);

    for (int i = 1; i <= n; ++i) {
        printf("%d ", res[i]);
    }

    printf("\n");
    return 0;
}

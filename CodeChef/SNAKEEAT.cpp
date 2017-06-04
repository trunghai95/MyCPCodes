#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int test, n, q, x, a[MAXN+2];

int main() {
    scanf("%d", &test);
    a[0] = 2e9;

    while (test --> 0) {
        scanf("%d %d", &n, &q);
        priority_queue<int, vector<int>, greater<int> > heap;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            heap.push(x);
        }

        while (heap.size() > 1) {
            a[heap.size()] = heap.top();

            heap.pop();
            heap.push(heap.top() + 1);
            heap.pop();
        }
        a[1] = heap.top();

        while (q --> 0) {
            scanf("%d", &x);
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2 + 1;
                if (a[mid] >= x) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            printf("%d\n", lo);
        }
    }
    return 0;
}

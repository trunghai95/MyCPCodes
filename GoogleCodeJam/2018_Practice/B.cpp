#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 26;
int test, n, a;

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);
        priority_queue<pii> heap;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            heap.push(pii(a, i));
            sum += a;
        }
        printf("Case #%d:", tt);
        while (sum) {
            pii p = heap.top();
            heap.pop();
            printf(" %c", 'A'+p.second);
            if (--p.first) {
                heap.push(p);
            }
            if (sum == 3 || sum == 1) {
                --sum;
                continue;
            }
            p = heap.top();
            heap.pop();
            printf("%c", 'A'+p.second);
            if (--p.first) {
                heap.push(p);
            }
            sum -= 2;
        }
        printf("\n");
    }
    return 0;
}
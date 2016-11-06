#include <bits/stdc++.h>

using namespace std;

int r, k, n, a[20], res;
queue<int> q;

int main() {
    scanf("%d %d %d", &r, &k, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        q.push(a[i]);
    }

    while (r --> 0) {
        int sum = 0, cnt = 0;
        while (cnt < n) {
            if (sum + q.front() > k) break;
            res += q.front();
            sum += q.front();
            q.push(q.front());
            q.pop();
            ++cnt;
        }
    }

    printf("%d\n", res);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct cmpHeap
{
    bool operator()(const ll& x, const ll& y) { return x > y; }
};

priority_queue<ll, vector<ll>, cmpHeap> heap;
int test, n;

int main()
{
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        ll x;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &x);
            heap.push(x);
        }

        ll res = 0;
        while (heap.size() >= 2)
        {
            x = heap.top();
            heap.pop();
            x += heap.top();
            heap.pop();
            heap.push(x);
            res += x;
        }

        printf("%lld\n", res);
        heap.pop();
    }
    return 0;
}

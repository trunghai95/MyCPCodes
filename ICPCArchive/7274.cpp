#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Cmp
{
    bool operator()(ll x, ll y) { return x > y; }
};

int test, n;
ll x, y;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);

    while (test--)
    {
        priority_queue<ll, vector<ll>, Cmp> heap;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &x);
            heap.push(x);
        }

        ll res = 0;
        while (heap.size() > 1)
        {
            x = heap.top(); heap.pop();
            y = heap.top(); heap.pop();
            res += x + y;
            heap.push(x + y);
        }

        printf("%lld\n", res);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

struct Node
{
    ll x, y, s, id;
};

bool cmp(const Node& a, const Node& b)
{
    if (a.s == b.s)
        return (a.x <= b.x && a.y <= b.y);
    return (a.s < b.s);
}

bool cmp2(const Node& a, const Node& b)
{
    return (a.x < b.x && a.y < b.y);
}

bool cmppii(const pii& x, const pii& y)
{
    return x.second < y.second;
}

Node node[100000];
ll n;
pii w[100000];

int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &node[i].x, &node[i].y);
        node[i].s = node[i].y - node[i].x;
    }

    for (ll i = 0; i < n; ++i)
    {
        scanf("%lld", &w[i].first);
        w[i].second = i;
    }

    sort(w, w + n);
    sort(node, node + n, cmp);

    for (ll i = 0; i < n; ++i)
    {
        if (w[i].first != node[i].s)
        {
            printf("NO");
            return 0;
        }
        w[i].first = node[i].id = i;
    }

    sort(w, w+n, cmppii);

    for (ll i = 0; i < n; ++i)
        if ((node[w[i].first].x + 1) * (node[w[i].first].y + 1) - 1 > i)
        {
            printf("NO");
            return 0;
        }

    printf("YES\n");
    for (ll i = 0; i < n; ++i)
        printf("%lld %lld\n", node[w[i].first].x, node[w[i].first].y);
    return 0;
}

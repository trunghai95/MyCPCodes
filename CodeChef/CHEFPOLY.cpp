// subtask 1
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second

int sign (pii p1, pii p2, pii p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (pii pt, pii v1, pii v2, pii v3)
{
    bool b1, b2, b3;

    b1 = sign(pt, v1, v2) < 0;
    b2 = sign(pt, v2, v3) < 0;
    b3 = sign(pt, v3, v1) < 0;

    return ((b1 == b2) && (b2 == b3));
}

int n, m, q;
pii red[111], black[3009];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &red[i].x, &red[i].y);

	int res = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &black[i].x, &black[i].y);
		res += PointInTriangle(black[i], red[1], red[2], red[3]);
	}

	scanf("%d", &q);
	while (q--)
		printf("%d\n", res);
	return 0;
}
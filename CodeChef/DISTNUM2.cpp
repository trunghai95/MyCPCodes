#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node
{
	vector<ll> val;
};

int n, q, k;
ll arr[100010], a, b, c, d, ans;
Node it[400010];

void ITinit(int node, int lef, int rig)
{
	// printf("%d %d %d\n", node, lef, rig);
	if (lef == rig)
	{
		it[node].val.push_back(arr[lef]);
		return;
	}

	int mid = ((lef + rig) >> 1);
	int c1 = (node << 1);
	int c2 = (node << 1) | 1;
	ITinit(c1, lef, mid);
	ITinit(c2, mid + 1, rig);
	int i1 = 0, i2 = 0;
	vector<ll> &v1 = it[c1].val;
	vector<ll> &v2 = it[c2].val;
	while (i1 < v1.size() && i2 < v2.size())
	{
		if (v1[i1] < v2[i2])
		{
			if (it[node].val.empty() || v1[i1] > it[node].val.back())
				it[node].val.push_back(v1[i1]);
			++i1;
		}
		else
		{
			if (it[node].val.empty() || v2[i2] > it[node].val.back())
				it[node].val.push_back(v2[i2]);
			++i2;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; ++i)
		scanf("%d", arr+i);

	ITinit(1, 1, n);
	
	while (q--)
	{
		scanf("%lld %lld %lld %lld %d", &a, &b, &c, &d, &k);
		int l = (a*max(ans, 0LL) + b) % n + 1;
		int r = (c*max(ans, 0LL) + d) % n + 1;
		if (l > r) swap(l, r);
		// làm gì nữa???
	}
	return 0;
}
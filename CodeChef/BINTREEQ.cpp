#include <bits/stdc++.h>

using namespace std;

int test, n, u, v;

int height(int x)
{
	int res = 0;
	while (x)
	{
		++res;
		x >>= 1;
	}
	return res;
}

int proc(int& x, vector<int>& v)
{
	int res = x, sz = v.size();
	for (int i = 0; i < sz && res <= n; ++i)
		res = (res << 1) | v[i];
	if (res > n)
		return -1;
	return res;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %d %d", &n, &u, &v);
		int hu = height(u), hv = height(v);
		if (hu > hv)
			swap(u, v), swap(hu, hv);

		vector<int> vu, vv;

		while (hv > hu)
		{
			vv.push_back(v&1);
			v >>= 1;
			--hv;
		}

		while (u - v)
		{
			vv.push_back(v&1);
			vu.push_back(u&1);
			v >>= 1;
			u >>= 1;
		}

		reverse(vv.begin(), vv.end());
		reverse(vu.begin(), vu.end());

		int lef = 1, rig = n;

		while (lef < rig)
		{
			int mid = ((lef + rig) >> 1) + 1;
			u = proc(mid, vu);
			v = proc(mid, vv);
			if (u == -1 || v == -1)
				rig = mid - 1;
			else
				lef = mid;
		}

		printf("%d\n", lef);
	}
	return 0;
}
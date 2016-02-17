#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
ll x[200010], prefix[200010];

ld f(int i, int j)
{
	ld res = prefix[i] - prefix[i-j-1] + prefix[n] - prefix[n-j];
	return res / (j*2 + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", x+i);

	if (n < 3)
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; ++i)
			printf("%lld ", x[i]);
		return 0;
	}

	sort(x+1, x+n+1);

	for (int i = 1; i <= n; ++i)
		prefix[i] = prefix[i-1] + x[i];

	ld mx = 0;
	int mxi = 1, mxj = 0;

	for (int i = 2; i < n; ++i)
	{
		int lef = 1, rig = min(n - i, i - 1);

		while (lef < rig)
		{
			int mid = (lef + rig) / 2;

			ld fij = f(i, mid);
			if (fij <= f(i, mid+1))
				lef = mid + 1;
			else
				rig = mid;
		}

		ld tmp = f(i, lef) - x[i];

		if (tmp > mx)
		{
			mx = tmp;
			mxi = i;
			mxj = lef;
		}
	}

	printf("%d\n", mxj*2 + 1);

	for (int i = mxi - mxj; i <= mxi; ++i)
		printf("%lld ", x[i]);
	for (int i = n - mxj + 1; i <= n; ++i)
		printf("%lld ", x[i]);

	return 0;
}
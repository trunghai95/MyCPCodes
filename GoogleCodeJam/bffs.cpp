// brute-force - O(n! * n^2)

#include <bits/stdc++.h>

using namespace std;

int test, n, f[1010];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d", &n);
		vector<int> per;
		for (int i = 1; i <= n; ++i)
			scanf("%d", f+i), per.push_back(i);
		if (n <= 3)
		{
			printf("Case #%d: %d\n", tt, n);
			continue;
		}
		int res = 1;

		do
		{
			// for (int i = 0; i < n; ++i)
			// 	cout << per[i] << ' ';
			int tmp = n;
			while (tmp > 1)
			{
				bool flag = true;
				for (int i = 0; i < tmp; ++i)
				{
					if (f[per[i]] != per[(i+1)%tmp] && f[per[i]] != per[(i-1+tmp)%tmp])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					break;
				--tmp;
			}
			res = max(res, tmp);
			// cout << tmp << '\n';
			// if (res == n)
			// 	break;
		}
		while (next_permutation(per.begin(), per.end()));

		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}
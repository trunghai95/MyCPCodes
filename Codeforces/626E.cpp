//WA
#include <bits/stdc++.h>

using namespace std;

int n, x[200010];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", x+i);

	if (n < 3)
	{
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
			printf("%d ", x[i]);
		return 0;
	}

	sort(x, x+n);
	double mx = 0;
	int mxn = 0, nn = 1, sum = x[0], type = -1;

	while (nn * 2 + 1 <= n)
	{
		sum += x[nn] + x[n - nn];

		double tmp = 1.0*sum/(nn*2+1) - x[nn];

		if (tmp > mx)
		{
			mx = tmp;
			mxn = nn;
			type = -1;
		}

		if (nn*2 + 2 <= n)
		{
			int sumtmp = sum + x[nn+1];
			tmp = max(tmp, 1.0*sumtmp/(nn*2+2) - 1.0*(x[nn] + x[nn+1])/2);

			if (tmp > mx)
			{
				mx = tmp;
				mxn = nn;
				type = 1;
			}

			sumtmp = sum + x[n - nn - 1];
			tmp = max(tmp, 1.0*sumtmp/(nn*2+2) - 1.0*(x[nn] + x[n-nn-1])/2);

			if (tmp > mx)
			{
				mx = tmp;
				mxn = nn;
				type = 2;
			}
		}

		++nn;
	}

	if (type == -1)
	{
		printf("%d\n", mxn*2 + 1);
		for (int i = 0; i <= mxn; ++i)
			printf("%d ", x[i]);
		for (int i = n - mxn; i < n; ++i)
			printf("%d ", x[i]);
	}
	else
	{
		printf("%d\n", mxn*2 + 2);
		if (type == 1)
		{
			for (int i = 0; i <= mxn + 1; ++i)
				printf("%d ", x[i]);
			for (int i = n - mxn; i < n; ++i)
				printf("%d ", x[i]);
		}
		else
		{
			for (int i = 0; i <= mxn; ++i)
				printf("%d ", x[i]);
			for (int i = n - mxn - 1; i < n; ++i)
				printf("%d ", x[i]);
		}
	}

	return 0;
}
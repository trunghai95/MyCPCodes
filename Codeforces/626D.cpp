#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[2010], n, cnt[5010], cntAcc[5010];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
		++cnt[abs(a[i] - a[j])];

	for (int i = 4999; i >= 0; --i)
		cntAcc[i] = cnt[i+1] + cntAcc[i+1];

	ll tot = n*(n-1)/2;
	tot = tot*tot*tot;
	ll cc = 0;

	for (int i = 1; i <= 5000; ++i)
	for (int j = 5000 - i; j >= 1; --j)
	{
		cc += (ll)cnt[i]*cnt[j]*cntAcc[i+j];
	}

	printf("%.12lf", 1.0*cc/tot);
	return 0;
}
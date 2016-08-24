#include <bits/stdc++.h>

using namespace std;

int n, a[100010], l[100010], r[100010], res;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	a[0] = -2e9;
	a[n+1] = 2e9;

	for (int i = 1; i <= n; ++i)
	if (a[i] > a[i-1])
		l[i] = l[i-1] + 1;
	else
		l[i] = 1;

	for (int i = n; i > 0; --i)
	if (a[i] < a[i+1])
		r[i] = r[i+1] + 1;
	else
		r[i] = 1;

	for (int i = 1; i <= n; ++i)
	{
		if (a[i+1] > a[i-1] + 1)
			res = max(res, l[i-1] + r[i+1] + 1);
		res = max(res, l[i-1] + 1);
		res = max(res, r[i+1] + 1);
	}

	printf("%d\n", res);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cntc[200], cntr[200];
char s[200];
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);

		for (int j = 0; j < n; ++j)
		if (s[j] == 'C')
			++cntr[i], ++cntc[j];
	}

	ll res = 0;
	for (int i = 0; i < n; ++i)
	{
		res += cntc[i]*(cntc[i]-1)/2 + cntr[i]*(cntr[i]-1)/2;
	}

	printf("%lld", res);
	return 0;
}
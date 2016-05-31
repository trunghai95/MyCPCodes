#include <bits/stdc++.h>

using namespace std;

int n, q, a[100000], m[100000][20], u, v, myPow[20];

void init()
{
	myPow[0] = 1;
	for (int i = 1; i < 20; ++i)
		myPow[i] = (myPow[i-1] << 1);

	for (int i = n-1; i >= 0; --i)
	{
		m[i][0] = a[i];
		for (int j = 1; i + myPow[j] <= n; ++j)
			m[i][j] = min(m[i][j-1], m[i + myPow[j-1]][j-1]);
	}
}

int query(int lef, int len)
{
	int k = 20, res = ~(1<<31);

	while (len)
	{
		while (myPow[--k] > len);
		res = min(res, m[lef][k]);
		lef += myPow[k];
		len -= myPow[k];
	}

	return res;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);
	init();

	scanf("%d", &q);
	while (q--)
	{
		scanf("%d %d", &u, &v);
		printf("%d\n", query(u, v-u+1));
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1000000;

int n, a[1010], res1a, res1b;
bool notPrime[MAXA*2+10];
vector<int> res2;

void init()
{
	for (int i = 2; i*i <= MAXA*2; ++i)
	if (!notPrime[i])
	{
		for (int j = i*i; j <= MAXA*2; j += i)
			notPrime[j] = true;
	}
}

int main()
{
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);

	for (int i = 1; i <= n && !res1a; ++i)
	for (int j = i + 1; j <= n && !res1a; ++j)
	if (!notPrime[a[i] + a[j]])
		res1a = a[i], res1b = a[j];

	for (int i = 1; i <= n; ++i)
	if (a[i] == 1)
		res2.push_back(a[i]);

	if (res2.empty())
		res2.push_back(a[1]);
	else for (int i = 1; i <= n; ++i)
	if (a[i] != 1 && !notPrime[a[i] + 1])
	{
		res2.push_back(a[i]);
		break;
	}

	// cout << res1a << ' ' << res1b << '\n';

	if (!res1a)
	{
		printf("%d\n", res2.size());
		for (int i = 0; i < res2.size(); ++i)
			printf("%d ", res2[i]);
	}
	else if (res2.size() > 2)
	{
		printf("%d\n", res2.size());
		for (int i = 0; i < res2.size(); ++i)
			printf("%d ", res2[i]);
	}
	else printf("2\n%d %d", res1a, res1b);
	return 0;
}
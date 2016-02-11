#include <bits/stdc++.h>

using namespace std;

struct cmp
{
	bool operator()(int x, int y) { return x > y; }
};

map<int,int,cmp> mp;
int n, a;

int main()
{
	scanf("%d %d", &n, &a);

	long long res = a;

	for (int i = 1; i < n; ++i)
	{
		scanf("%d", &a);
		res = __gcd((int)res, a);
	}

	printf("%lld", res * n);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll BASE = 29;
const ll MODD = 1e9 + 7;

int n;
char name[40];
map<ll, int> mp;

ll hash()
{
	int len = strlen(name);
	ll res = 0;
	for (int i = 0; i < len; ++i)
		res = (res * BASE + name[i]) % MODD;
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", name);
		ll h = hash();
		if (++mp[h] == 1)
			printf("OK\n");
		else
			printf("%s%d\n", name, mp[h] - 1);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
map<string, ll> mp;
char s[20];

void init()
{
	for (int i = 0; i < 10; ++i)
		mp[string(1, '0' + (9 + i) % 10)] = i + 1989;
}

ll solve(string str)
{
	if (str.length() == 1)
		return mp[str];
	map<string, ll>::iterator it = mp.find(str);
	if (it != mp.end())
		return (*it).second;

	ll mn = solve(string(str.begin() + 1, str.end()));
	ll step = 1;
	for (int i = str.length(); i > 0; --i)
		step *= 10;
	ll start = 0;
	for (int i = 0; i < (int)str.length(); ++i)
		start = start * 10 + str[i] - 48;
	while (start <= mn)
		start += step;
	return (mp[str] = start);
}

int main()
{
	init();
	scanf("%d", &n);

	while (n--)
	{
		scanf("%s", s);
		printf("%lld\n", solve(string(s+4)));
	}
	return 0;
}
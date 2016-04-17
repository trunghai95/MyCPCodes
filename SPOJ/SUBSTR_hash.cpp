//Why WA :'(

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const ll BASE = 29;

char sa[1000010], sb[1000010];
ll ha, hb, poww[1000010];

void init()
{
	poww[0] = 1;
	for (int i = 1; i <= 1000000; ++i)
		poww[i] = (poww[i-1] * BASE) % MODD;
}

int main()
{
	init();
	scanf("%s %s", sa, sb);

	int na = strlen(sa), nb = strlen(sb);
	if (na < nb)
		return 0;

	for (int i = 0; i < nb; ++i)
	{
		ha = (ha * BASE + sa[i] - 'a' + 1) % MODD;
		hb = (hb * BASE + sb[i] - 'a' + 1) % MODD;
	}

	if (ha == hb)
		printf("1 ");

	for (int i = nb; i < na; ++i)
	{
		ha = (ha - (sa[i - nb] - 'a' + 1) * poww[nb - 1] % MODD + MODD) % MODD;
		ha = (ha * BASE + sa[i] - 'a' + 1) % MODD;
		if (ha == hb)
			printf("%d ", i - nb + 2);
	}
	return 0;
}
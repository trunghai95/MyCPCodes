//wa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1000000007;
const ll BASE = 29;

int d;
char s[1000010];
ll hash[1000010], Pow[1000010];

void init()
{
	Pow[0] = 1;

	for (int i = 1; i <= 1000000; ++i)
		Pow[i] = (Pow[i-1] * BASE) % MODD;
}

ll hashCal(int i, int j)
{
	if (j < 0 || i > j)
		return 0;

	if (i == 0)
		return hash[j];

	return (hash[j] - hash[i-1] * Pow[j - i + 1] + MODD * MODD) % MODD;
}

int main()
{
	init();
	scanf("%d", &d);

	while (d--)
	{
		scanf("%s", s);
		int len = strlen(s);
		if (len == 1)
		{
			printf("NO\n");
			continue;
		}
		hash[0] = s[0] - 'a' + 1;
		for (int i = 1; i < len; ++i)
			hash[i] = (hash[i-1] * BASE + s[i] - 'a' + 1) % MODD;

		// for (int i = 0; i < len; ++i)
		// 	printf("%lld ", hash[i]);
		// printf("\n");

		if (len & 1)
		{
			// printf("%lld %lld\n", hashCal(0, len/2 - 1), hashCal(len/2 + 1, len - 1));
			if (hashCal(0, len/2 - 1) == hashCal(len/2 + 1, len - 1))
			{
				printf("YES\n");
				continue;
			}

			ll tmp = hashCal(len/2 + 1, len - 1);
			bool done = false;
			for (int i = 0; i < len/2; ++i)
			{
				ll h = (hashCal(0, i - 1) * Pow[len/2 - i] + hashCal(i + 1, len/2)) % MODD;
				if (h == tmp)
				{
					printf("YES\n");
					done = true;
					break;
				}
			}

			if (done) continue;

			tmp = hashCal(0, len/2 - 1);
			for (int i = len/2 + 1; i < len; ++i)
			{
				ll h = (hashCal(len/2, i - 1) * Pow[len - i - 1] + hashCal(i + 1, len - 1)) % MODD;
				if (h == tmp)
				{
					printf("YES\n");
					done = true;
					break;
				}
			}
			if (!done)
				printf("NO\n");
		}
		else
		{
			if (hashCal(0, len/2 - 1) == hashCal(len/2, len - 1))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}